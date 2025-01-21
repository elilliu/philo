/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:38:24 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/22 00:12:12 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *structure)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)structure;
	philo = data->philo[data->current];
	// printf("num: %d\n", philo->num);
	pthread_mutex_lock(&data->mutex);
	while (data->active)
	{
		if (elapsed_time(philo->last_meal) > data->time_to_die)
			return (ft_die(data, philo), NULL);
		pthread_mutex_unlock(&data->mutex);
		// printf("left fork: %d\n", philo->left_fork.available);
		// printf("right fork: %d\n", philo->right_fork->available);
		pthread_mutex_lock(&philo->left_fork.mutex);
		// printf("ICI\n");
		if (philo->right_fork)
			pthread_mutex_lock(&philo->right_fork->mutex);
		// printf("LA\n");
		if (philo->right_fork && philo->right_fork->available && philo->left_fork.available)
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
	}
	return (NULL);
}
