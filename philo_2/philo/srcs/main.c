/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/28 19:48:42 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_philo(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex);
	data->current = i;
	pthread_mutex_unlock(&data->mutex);
	if (pthread_create(&data->philo[i]->thread, NULL, routine, data))
		return (pthread_create_error(), free_all(data, data->nb_of_philo), 0);
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

void	set_start_time(t_data *data)
{
	int	i;

	i = 0;
	while (data->philo[i])
	{
		data->philo[i]->last_meal = data->start;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	int			i;

	if (verif_args(ac, av) == 0)
		return (1);
	if (!data_init(&data, ac, av))
		return (1);
	data.philo = malloc(sizeof(t_philo) * data.nb_of_philo);
	if (!data.philo)
		return (malloc_error(), free_data(&data), 1);
	if (!init_philos(&data))
		return (1);
	i = 0;
	while (data.philo[i])
	{
		if (!create_philo(&data, i))
			return (1);
		i++;
	}
	pthread_mutex_lock(&data.mutex);
	gettimeofday(&data.start, NULL);
	set_start_time(&data);
	data.active = true;
	pthread_mutex_unlock(&data.mutex);
	if (!join_threads(&data))
		return (1);
	free_all(&data, data.nb_of_philo);
	return (0);
}
