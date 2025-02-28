/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:13:21 by elilliu           #+#    #+#             */
/*   Updated: 2025/02/28 19:34:43 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	malloc_error(void)
{
	write(2, "An error occured while allocating memory\n", 41);
}

void	pthread_create_error(void)
{
	write(2, "An error occured while creating a thread\n", 41);
}

void	mutex_init_error(void)
{
	write(2, "An error occured while initializing a mutex\n", 44);
}
