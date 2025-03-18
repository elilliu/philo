/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:29:29 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/04 14:16:56 by elilliu          ###   ########.fr       */
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
	printf("%ld %d has taken a fork\n",
		elapsed_time(data->start), philo->num);
	printf("%ld %d has taken a fork\n",
		elapsed_time(data->start), philo->num);
	pthread_mutex_unlock(&data->write);
}

void	eats(t_data *data, t_philo *philo)
{
	take_forks(data, philo);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_lock(&data->write);
	printf("%ld %d is eating\n", elapsed_time(data->start), philo->num);
	pthread_mutex_unlock(&data->write);
}

int	ft_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->mutex);
	if (data->active)
	{
		philo->thinking = false;
		pthread_mutex_unlock(&data->mutex);
		eats(data, philo);
		if (data->time_to_eat > data->time_to_die)
			return (usleep(data->time_to_die * 1000), 0);
		usleep(data->time_to_eat * 1000);
		pthread_mutex_lock(&data->mutex);
		philo->meals++;
		pthread_mutex_unlock(&data->mutex);
		verif_meals(data);
		put_forks(philo);
	}
	else
	{
		pthread_mutex_unlock(&philo->left_fork.mutex);
		if (philo->right_fork)
			pthread_mutex_unlock(&philo->right_fork->mutex);
		pthread_mutex_unlock(&data->mutex);
	}
	return (1);
}
