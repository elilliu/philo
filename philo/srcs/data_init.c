/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:42:52 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/23 18:51:13 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		data->philo[i] = malloc(sizeof(t_philo));
		if (!data->philo[i])
			return ;
		// data->philo[i]->alive = true;
		data->philo[i]->thinking = true;
		data->philo[i]->num = i + 1;
		data->philo[i]->meals = 0;
		data->philo[i]->last_meal = data->start;
		pthread_mutex_init(&data->philo[i]->left_fork.mutex, NULL);
		pthread_mutex_lock(&data->philo[i]->left_fork.mutex);
		data->philo[i]->left_fork.available = true;
		pthread_mutex_unlock(&data->philo[i]->left_fork.mutex);
		if (i)
			data->philo[i]->right_fork = &data->philo[i - 1]->left_fork;
		i++;
	}
	if (i != 1)
		data->philo[0]->right_fork = &data->philo[i - 1]->left_fork;
	else
		data->philo[0]->right_fork = NULL;
	data->philo[i] = NULL;
}

void	data_init(t_data *data, int ac, char **av)
{
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_of_meals = ft_atoi(av[5]);
	else
		data->nb_of_meals = -1;
	data->active = true;
	gettimeofday(&data->start, NULL);
	pthread_mutex_init(&data->mutex, NULL);
	pthread_mutex_init(&data->write, NULL);
}
