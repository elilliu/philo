/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:40:15 by elilliu           #+#    #+#             */
/*   Updated: 2024/05/18 02:30:18 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_philo philo;

    if (ac < 5 || ac > 6)
        return (arg_error(), 1);
    philo.num = ft_atoi(av[1]);
    philo.die = ft_atoi(av[2]);
    philo.eat = ft_atoi(av[3]);
    philo.sleep = ft_atoi(av[4]);
    if (ac == 6)
        philo.meals = ft_atoi(av[5]);
    if (philo.num >= 100)
        return (1);
    return (0);
}
