/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:31:42 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/20 23:11:32 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	put_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork.mutex);
	philo->left_fork.available = true;
	pthread_mutex_unlock(&philo->left_fork.mutex);
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->available = true;
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	take_forks(t_data *data, t_philo *philo)
{
	philo->left_fork.available = false;
	pthread_mutex_unlock(&philo->left_fork.mutex);
	philo->right_fork->available = false;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_lock(&data->write);
	printf("[%ldms] %d has taken his left fork\n", elapsed_time(data->start), philo->num);
	printf("[%ldms] %d has taken his right fork\n", elapsed_time(data->start), philo->num);
	pthread_mutex_unlock(&data->write);
}

int	ft_eat(t_data *data, t_philo *philo)
{
	philo->thinking = false;
	take_forks(data, philo);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_lock(&data->write);
	printf("[%ldms] %d is eating\n", elapsed_time(data->start), philo->num);
	pthread_mutex_unlock(&data->write);
	if (data->time_to_eat > data->time_to_sleep)
	{
		usleep(data->time_to_die * 1000);
		ft_die(philo);
		return (0);
	}
	usleep(data->time_to_eat * 1000);
	philo->meals++;
	put_forks(philo);
	return (1);
}

void	sleeping(int num)
{
	printf("timestamp %d is sleeping\n", num);
}

void	ft_think(t_data *data, t_philo *philo)
{
	if (philo->thinking == false)
	{
		philo->thinking = true;
		pthread_mutex_lock(&data->write);
		printf("[%ldms] %d is thinking\n", elapsed_time(data->start), philo->num);
		pthread_mutex_unlock(&data->write);
	}
}

void	death(int num)
{
	printf("timestamp %d died\n", num);
}
