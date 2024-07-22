/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2024/07/14 12:45:11 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *structure)
{
	t_data	*data;
	t_philo	philo;

	data = (t_data *)structure;
	philo = data->philo[data->current];
	if (pthread_mutex_lock(&data->mutex))
	{
		printf("error unlocking mutex\n");
		return (NULL);
	}
	printf("je suis le philosophe numero %d\n", philo.num);
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}

void	init_philo(t_data *data, int i)
{
	data->philo[i].num = i + 1;
	data->current = i;
	pthread_create(&data->philo[i].thread, NULL, routine, (void *)data);
	usleep(1000);
}

int	main(int ac, char **av)
{
	t_data		data;
	int			i;

	data_init(&data, ac, av);
	pthread_mutex_init(&data.mutex, NULL);
	i = 0;
	data.philo = malloc(sizeof(t_philo) * data.nb_of_philo);
	if (!data.philo)
		return (1);
	while (i < data.nb_of_philo)
	{
		init_philo(&data, i);
		i++;
	}
	i = 0;
	while (i < data.nb_of_philo)
	{
		pthread_join(data.philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&data.mutex);
	return (0);
}
