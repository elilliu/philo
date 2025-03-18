/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:31:42 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/04 12:19:15 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_sleep(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->mutex);
	if (data->active)
	{
		pthread_mutex_unlock(&data->mutex);
		pthread_mutex_lock(&data->write);
		printf("%ld %d is sleeping\n", elapsed_time(data->start), philo->num);
		pthread_mutex_unlock(&data->write);
		if ((data->time_to_eat + data->time_to_sleep) > data->time_to_die)
		{
			usleep((data->time_to_die - data->time_to_eat) * 1000);
			return (0);
		}
		usleep(data->time_to_sleep * 1000);
	}
	else
		pthread_mutex_unlock(&data->mutex);
	return (1);
}

void	ft_think(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->mutex);
	if (data->active)
	{
		if (!philo->thinking)
		{
			philo->thinking = true;
			pthread_mutex_unlock(&data->mutex);
			pthread_mutex_lock(&data->write);
			printf("%ld %d is thinking\n", elapsed_time(data->start),
				philo->num);
			pthread_mutex_unlock(&data->write);
		}
		else
			pthread_mutex_unlock(&data->mutex);
	}
	else
		pthread_mutex_unlock(&data->mutex);
}

void	ft_die(t_data *data, t_philo *philo)
{
	if (data->active)
	{
		pthread_mutex_lock(&data->write);
		printf("%ld %d died\n", elapsed_time(data->start), philo->num);
		pthread_mutex_unlock(&data->write);
	}
	data->active = false;
}
