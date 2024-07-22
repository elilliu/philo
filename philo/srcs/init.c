/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:42:52 by elilliu           #+#    #+#             */
/*   Updated: 2024/07/14 18:12:19 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	data_init(t_data *data, int ac, char **av)
{
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_of_meals = ft_atoi(av[5]);
	pthread_mutex_init(&data->write.mutex, NULL);
}
