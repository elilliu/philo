/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:42:52 by elilliu           #+#    #+#             */
/*   Updated: 2024/12/19 19:14:45 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philo(t_philo *philo)
{
	t_philo	philo;

	philo->prev = NULL;
	philo->next = NULL;
	philo->die = 0;
	philo->num = 0;
	philo->last_meal = NULL;
}

void	init_philos(t_data *data)
{
	int		i;
	t_philo	*current;

	i = 0;
	current = data->philo;
	while (i < data->nb_of_philo)
	{
		init_philo(current);
		current = current->next;
		i++;
	}
}

void	data_init(t_data *data, int ac, char **av)
{
	data->nb_of_philo = ft_pos_atoi(av[1]);
	data->time_to_die = ft_pos_atoi(av[2]);
	data->time_to_eat = ft_pos_atoi(av[3]);
	data->time_to_sleep = ft_pos_atoi(av[4]);
	if (ac == 6)
		data->nb_of_meals = ft_pos_atoi(av[5]);
	pthread_mutex_init(&data->mutex, NULL);
	pthread_mutex_init(&data->write, NULL);
}
