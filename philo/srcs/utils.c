/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:46:04 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/02/28 19:56:34 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_philos(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&data->philo[i]->left_fork.mutex);
		free(data->philo[i]);
		i++;
	}
	free(data->philo);
}

void	free_data(t_data *data)
{
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->mutex);
}

void	free_all(t_data *data, int nb)
{
	free_philos(data, nb);
	free_data(data);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (nptr[i])
	{
		nb = nb * 10 + nptr[i] - '0';
		if (nb > 2147483647)
			return (-1);
		i++;
	}
	return (nb);
}

long	elapsed_time(struct timeval start)
{
	struct timeval	current;
	time_t			time;

	gettimeofday(&current, NULL);
	time = (current.tv_sec - start.tv_sec) * 1000000
		+ (current.tv_usec - start.tv_usec);
	return (time / 1000);
}
