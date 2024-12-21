/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:46:04 by elilliu@stu       #+#    #+#             */
/*   Updated: 2024/12/21 00:50:18 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_data(t_data *data)
{
	free(data->philo);
	pthread_mutex_destroy(&data->write);
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
