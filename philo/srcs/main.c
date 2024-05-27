/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2024/05/27 20:25:59 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int init_struct(t_philo *philo, int ac, char **av)
{
	philo->num = ft_atoi(av[1]);
	if (philo->num == 3000000000)
		return (0);
	philo->die = ft_atoi(av[2]);
	if (philo->die == 3000000000)
		return (0);
	philo->eat = ft_atoi(av[3]);
	if (philo->eat == 3000000000)
		return (0);
	philo->sleep = ft_atoi(av[4]);
	if (philo->sleep == 3000000000)
		return (0);
	if (ac == 6)
	{
		philo->meals = ft_atoi(av[5]);
		if (philo->meals == 3000000000)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo philo;

	if (ac < 5 || ac > 6)
		return (arg_error(), 1);
	if (verif_args(ac, av) == 0)
		return (digit_error(), 1);
	if (init_struct(&philo, ac, av) == 0)
		return (digit_error(), 1);
	if (philo.num > 200)
		return (1);
	return (0);
}
