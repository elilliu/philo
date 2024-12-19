/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:46:04 by elilliu@stu       #+#    #+#             */
/*   Updated: 2024/12/19 17:56:59 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_data(t_data *data)
{
	free(data->philo);
	pthread_mutex_destroy(&data->write.mutex);
}

long	ft_pos_atoi(const char *nptr)
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
