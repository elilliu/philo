/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2024/12/21 01:24:48 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *structure)
{
	t_data	*data;

	data = (t_data *)structure;
	pthread_mutex_lock(&data->write);
	printf("je suis le philosophe numero %d\n", data->philo->num);
	pthread_mutex_unlock(&data->write);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*first;

	if (verif_args(ac, av) == 0)
		return (1);
	data_init(&data, ac, av);
	data.philo = malloc(sizeof(t_philo) * data.nb_of_philo);
	if (!data.philo)
		return (free_data(&data), 1);
	init_philos(&data);
	first = data.philo;
	while (data.philo)
	{
		pthread_create(&data.philo->thread, NULL, routine, &data);
		usleep(100);
		data.philo = data.philo->next;
	}
	data.philo = first;
	while (data.philo)
	{
		pthread_join(data.philo->thread, NULL);
		data.philo = data.philo->next;
	}
	free_data(&data);
	return (0);
}
