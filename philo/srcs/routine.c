/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:38:24 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/23 18:27:01 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *structure)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)structure;
	pthread_mutex_lock(&data->mutex);
	philo = data->philo[data->current];
	while (data->active)
	{
		if (elapsed_time(philo->last_meal) > data->time_to_die)
			return (ft_die(data, philo), NULL);
		pthread_mutex_unlock(&data->mutex);
		pthread_mutex_lock(&philo->left_fork.mutex);
		if (philo->right_fork)
			pthread_mutex_lock(&philo->right_fork->mutex);
		if (philo->right_fork && philo->right_fork->available && philo->left_fork.available && has_prio(data, philo))
		{
			if (!ft_eat(data, philo) || !ft_sleep(data, philo))
				return (pthread_mutex_lock(&data->mutex), ft_die(data, philo), NULL);
		}
		else
		{
			pthread_mutex_unlock(&philo->left_fork.mutex);
			if (philo->right_fork)
				pthread_mutex_unlock(&philo->right_fork->mutex);
		}
		ft_think(data, philo);
		pthread_mutex_lock(&data->mutex);
	}
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}
