/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_prio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:05:32 by elilliu           #+#    #+#             */
/*   Updated: 2025/03/03 17:19:14 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	has_prio(t_data *data, t_philo *philo)
{
	int		i;
	t_philo	*prev;
	t_philo	*next;

	if (philo->meals == 0)
		return (1);
	i = philo->num;
	if (i != 1)
		prev = data->philo[i - 2];
	else
		prev = data->philo[data->nb_of_philo - 1];
	if (i != data->nb_of_philo)
		next = data->philo[i];
	else
		next = data->philo[0];
	if (elapsed_time(prev->last_meal) > elapsed_time(philo->last_meal))
		return (0);
	else if (elapsed_time(next->last_meal) > elapsed_time(philo->last_meal))
		return (0);
	return (1);
}
