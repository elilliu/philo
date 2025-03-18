/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:42:52 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/04 15:46:31 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	basic_features(t_data *data, int i)
{
	data->philo[i]->thinking = true;
	data->philo[i]->alive = false;
	data->philo[i]->num = i + 1;
	data->philo[i]->meals = 0;
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		data->philo[i] = malloc(sizeof(t_philo));
		if (!data->philo[i])
			return (malloc_error(data), free_all(data, i), 0);
		basic_features(data, i);
		if (pthread_mutex_init(&data->philo[i]->left_fork.mutex, NULL))
			return (mutex_init_error(data), free_all(data, i), 0);
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
	return (1);
}

int	data_init(t_data *data, int ac, char **av)
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
	data->can_go = true;
	if (pthread_mutex_init(&data->write, NULL)
		|| pthread_mutex_init(&data->mutex, NULL))
		return (mutex_init_error(data), 0);
	return (1);
}
