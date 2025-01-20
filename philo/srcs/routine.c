/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:38:24 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/20 23:14:50 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *structure)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)structure;
	philo = data->philo[data->current - 1];
	while (philo->alive == true && data->active)
	{
		if (elapsed_time(philo->last_meal) > data->time_to_die)
			return (ft_die(data, philo), NULL);
		pthread_mutex_lock(&philo->left_fork.mutex);
		pthread_mutex_lock(&philo->right_fork->mutex);
		if (philo->right_fork->available == true && philo->left_fork.available == true)
		{
			if (!ft_eat(data, philo))
				return (ft_die(data, philo));
			ft_sleep(data, philo);
		}
		else
		{
			pthread_mutex_unlock(&philo->left_fork.mutex);
			pthread_mutex_unlock(&philo->right_fork->mutex);
		}
		ft_think(data, philo);
	}
}
