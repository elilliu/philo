/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:31:42 by elilliu           #+#    #+#             */
/*   Updated: 2024/07/08 16:51:49 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_fork(int num)
{
	printf("timestamp %d has taken a fork\n", num);
}

void	eating(int num)
{
	printf("timestamp %d is eating\n", num);
}

void	sleeping(int num)
{
	printf("timestamp %d is sleeping\n", num);
}

void	thinking(int num)
{
	printf("timestamp %d is thinking", num);
}

void	death(int num)
{
	printf("timestamp %d died\n", num);
}
