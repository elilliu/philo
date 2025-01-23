/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/23 18:48:03 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	init_philos(&data);
	i = 0;
	while (data.philo[i])
	{
		pthread_mutex_lock(&data.mutex);
		data.current = i;
		pthread_mutex_unlock(&data.mutex);
		pthread_create(&data.philo[i]->thread, NULL, routine, &data);
		usleep(500);
		i++;
	}
	i = 0;
	while (data.philo[i])
	{
		pthread_join(data.philo[i]->thread, NULL);
		i++;
	}
	// i = 0;
	// while (data.philo[i])
	// {
	// 	printf("%d has eaten %d meals\n", data.philo[i]->num, data.philo[i]->meals);
	// 	i++;
	// }
	// printf("%ldms Simulation is over\n", elapsed_time(data.start));
	free_data(&data);
	return (0);
}
