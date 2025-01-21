/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:46:04 by elilliu@stu       #+#    #+#             */
/*   Updated: 2025/01/21 23:03:42 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->philo[i])
	{
		pthread_mutex_destroy(&data->philo[i]->left_fork.mutex);
		free(data->philo[i]);
		i++;
	}
	free(data->philo);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->mutex);
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
	time = (current.tv_sec - start.tv_sec) * 1000000 + (current.tv_usec - start.tv_usec);
	return (time / 1000);
}
