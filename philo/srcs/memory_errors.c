/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:13:21 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/04 12:12:03 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	malloc_error(t_data *data)
{
	pthread_mutex_lock(&data->write);
	write(2, "An error occured while allocating memory\n", 41);
	pthread_mutex_unlock(&data->write);
}

void	pthread_create_error(t_data *data)
{
	pthread_mutex_lock(&data->write);
	write(2, "An error occured while creating a thread\n", 41);
	pthread_mutex_unlock(&data->write);
}

void	mutex_init_error(t_data *data)
{
	pthread_mutex_lock(&data->write);
	write(2, "An error occured while initializing a mutex\n", 44);
	pthread_mutex_unlock(&data->write);
}
