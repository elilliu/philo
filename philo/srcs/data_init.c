/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:42:52 by elilliu           #+#    #+#             */
/*   Updated: 2024/12/21 01:24:25 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philo(t_philo *philo)
{
	philo->prev = NULL;
	philo->next = NULL;
	philo->die = 0;
	philo->num = 1;
	philo->last_meal = (time_t) NULL;
}

void	init_philos(t_data *data)
{
	int		i;
	t_philo	*first;
	t_philo	*tmp;

	i = 0;
	data->philo = malloc(sizeof(t_philo));
	init_philo(data->philo);
	first = data->philo;
	while (i < data->nb_of_philo)
	{
		if (data->philo->prev)
			data->philo->num = data->philo->prev->num + 1;
		if (i < data->nb_of_philo - 1)
		{
			data->philo->next = malloc(sizeof(t_philo));
			init_philo(data->philo->next);
			tmp = data->philo;
			data->philo = data->philo->next;
			data->philo->prev = tmp;
		}
		i++;
	}
	data->philo = first;
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
