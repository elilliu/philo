/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/04 15:51:41 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_philo(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex);
	data->can_go = false;
	data->current = i;
	if (pthread_create(&data->philo[i]->thread, NULL, routine, data))
		return (pthread_create_error(data),
			free_all(data, data->nb_of_philo), 0);
	pthread_mutex_unlock(&data->mutex);
	return (1);
}

int	create_odd_philos(t_data *data)
{
	int	i;

	i = 0;
	if (!create_philo(data, i))
		return (0);
	i += 2;
	while (data->philo[i - 1] && data->philo[i])
	{
		pthread_mutex_lock(&data->mutex);
		while (!data->can_go)
		{
			pthread_mutex_unlock(&data->mutex);
			usleep(80);
			pthread_mutex_lock(&data->mutex);
		}
		pthread_mutex_unlock(&data->mutex);
		if (!create_philo(data, i))
			return (0);
		i += 2;
	}
	return (1);
}

int	create_even_philos(t_data *data)
{
	int	i;

	i = 1;
	while (data->philo[i - 1] && data->philo[i])
	{
		pthread_mutex_lock(&data->mutex);
		while (!data->can_go)
		{
			pthread_mutex_unlock(&data->mutex);
			usleep(80);
			pthread_mutex_lock(&data->mutex);
		}
		pthread_mutex_unlock(&data->mutex);
		if (!create_philo(data, i))
			return (0);
		i += 2;
	}
	return (1);
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (data->philo[i])
	{
		if (pthread_join(data->philo[i]->thread, NULL))
			return (free_all(data, data->nb_of_philo), 0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data		data;

	if (verif_args(ac, av) == 0)
		return (1);
	if (!data_init(&data, ac, av))
		return (1);
	data.philo = malloc(sizeof(t_philo) * data.nb_of_philo);
	if (!data.philo)
		return (malloc_error(&data), free_data(&data), 1);
	if (!init_philos(&data))
		return (1);
	gettimeofday(&data.start, NULL);
	if (!create_odd_philos(&data) || !create_even_philos(&data))
		return (1);
	if (!join_threads(&data))
		return (1);
	free_all(&data, data.nb_of_philo);
	return (0);
}
