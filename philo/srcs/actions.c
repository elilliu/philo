/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:31:42 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/22 00:10:34 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	verif_meals(t_data *data)
{
	int	i;

	if (data->nb_of_meals != -1)
	{
		pthread_mutex_lock(&data->mutex);
		i = 0;
		while (data->philo[i])
		{
			if (data->philo[i]->meals < data->nb_of_meals)
			{
				pthread_mutex_unlock(&data->mutex);
				return ;
			}
			i++;
		}
		data->active = false;
		pthread_mutex_unlock(&data->mutex);
	}
}

void	put_forks(t_philo *philo)
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
	// printf("ICI\n");
	if (data->active)
	{
		philo->thinking = false;
		take_forks(data, philo);
		gettimeofday(&philo->last_meal, NULL);
		pthread_mutex_lock(&data->write);
		printf("[%ldms] %d is eating\n", elapsed_time(data->start), philo->num);
		pthread_mutex_unlock(&data->write);
		if (data->time_to_eat > data->time_to_die)
		{
			usleep(data->time_to_die * 1000);
			return (0);
		}
		usleep(data->time_to_eat * 1000);
		philo->meals++;
		verif_meals(data);
		put_forks(philo);
	}
	return (1);
}

int	ft_sleep(t_data *data, t_philo *philo)
{
	if (data->active)
	{
		pthread_mutex_lock(&data->write);
		printf("[%ldms] %d is sleeping\n", elapsed_time(data->start), philo->num);
		pthread_mutex_unlock(&data->write);
		if ((data->time_to_eat + data->time_to_sleep) > data->time_to_die)
		{
			usleep((data->time_to_die - data->time_to_eat) * 1000);
			return (0);
		}
		usleep(data->time_to_sleep * 1000);
	}
	return (1);
}

void	ft_think(t_data *data, t_philo *philo)
{
	if (!philo->thinking)
	{
		philo->thinking = true;
		pthread_mutex_lock(&data->write);
		printf("[%ldms] %d is thinking\n", elapsed_time(data->start), philo->num);
		pthread_mutex_unlock(&data->write);
	}
}

void	ft_die(t_data *data, t_philo *philo)
{
	data->active = false;
	pthread_mutex_unlock(&data->mutex);
	pthread_mutex_lock(&data->write);
	printf("[%ldms] %d has died\n", elapsed_time(data->start), philo->num);
	pthread_mutex_unlock(&data->write);
}
