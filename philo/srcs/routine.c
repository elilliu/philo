/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:38:24 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/04 15:51:46 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	even(t_data *data, t_philo *philo)
{
	if (philo->right_fork)
		pthread_mutex_lock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->left_fork.mutex);
	if (philo->right_fork && philo->right_fork->available
		&& philo->left_fork.available && has_prio(data, philo))
	{
		if (!ft_eat(data, philo) || !ft_sleep(data, philo))
			return (pthread_mutex_lock(&data->mutex),
				ft_die(data, philo), 0);
	}
	else
	{
		if (philo->right_fork)
			pthread_mutex_unlock(&philo->right_fork->mutex);
		pthread_mutex_unlock(&philo->left_fork.mutex);
	}
	return (1);
}

int	odd(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork.mutex);
	if (philo->right_fork)
		pthread_mutex_lock(&philo->right_fork->mutex);
	if (philo->right_fork && philo->right_fork->available
		&& philo->left_fork.available && has_prio(data, philo))
	{
		if (!ft_eat(data, philo) || !ft_sleep(data, philo))
			return (pthread_mutex_lock(&data->mutex),
				ft_die(data, philo), 0);
	}
	else
	{
		pthread_mutex_unlock(&philo->left_fork.mutex);
		if (philo->right_fork)
			pthread_mutex_unlock(&philo->right_fork->mutex);
	}
	return (1);
}

void	*philo_routine(t_data *data, t_philo *philo)
{
	if (elapsed_time(philo->last_meal) > data->time_to_die)
		return (ft_die(data, philo), NULL);
	pthread_mutex_unlock(&data->mutex);
	if (philo->num % 2)
	{
		if (!odd(data, philo))
			return (NULL);
	}
	else
	{
		if (!even(data, philo))
			return (NULL);
	}
	ft_think(data, philo);
	pthread_mutex_lock(&data->mutex);
	return (NULL);
}

void	*routine(void *structure)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)structure;
	pthread_mutex_lock(&data->mutex);
	philo = data->philo[data->current];
	philo->alive = true;
	data->can_go = true;
	gettimeofday(&philo->last_meal, NULL);
	while (data->active)
		philo_routine(data, philo);
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}
