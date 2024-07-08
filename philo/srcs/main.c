/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2024/07/08 18:01:28 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	data_init(t_data *data, int ac, char **av)
{
	data->nb_of_philo = av[1];
	data->time_to_die = (size_t)av[2];
	data->time_to_eat = (size_t)av[3];
	data->time_to_sleep = (size_t)av[4];
	if (ac == 6)
		data->nb_of_meals = av[5];
}

int	main(int ac, char **av)
{
	t_data			data;
	pthread_mutex_t	mutex;

	data_init(&data, ac, av);
}
