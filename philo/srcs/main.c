/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2024/12/19 18:43:30 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *structure)
{
	t_data	*data;
	t_philo	philo;

	data = (t_data *)structure;
	philo = data->philo[data->current];
	printf("creating thread for philo current: %d, philo.num: %d\n", data->current, data->philo[data->current].num);
	if (pthread_mutex_lock(&data->write.mutex))
	{
		printf("error locking mutex\n");
		return (NULL);
	}
	printf("je suis le philosophe numero %d\n", philo.num);
	pthread_mutex_unlock(&data->write.mutex);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		data;
	int			i;

	if (verif_args(ac, av) == 0)
		return (1);
	data_init(&data, ac, av);
	data.philo = malloc(sizeof(t_philo) * data.nb_of_philo);
	if (!data.philo)
		return (free_data(&data), 1);
	init_philo(&data);
	i = 0;
	while (i < data.nb_of_philo)
	{
		pthread_join(data.philo[i].thread, NULL);
		i++;
	}
	free_data(&data);
	return (0);
}
