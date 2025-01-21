/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/21 23:36:01 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// void	*routine(void *structure)
// {
// 	t_data	*data;

// 	data = (t_data *)structure;
// 	pthread_mutex_lock(&data->write);
// 	printf("je suis le philosophe numero %d\n", data->philo[data->current]->num);
// 	pthread_mutex_unlock(&data->write);
// 	return (NULL);
// }

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
		data.current = i;
		pthread_create(&data.philo[i]->thread, NULL, routine, &data);
		usleep(100);
		i++;
	}
	i = 0;
	while (data.philo[i])
	{
		pthread_join(data.philo[i]->thread, NULL);
		i++;
	}
	free_data(&data);
	return (0);
}
