/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:34:11 by elilliu           #+#    #+#             */
/*   Updated: 2024/12/19 17:57:58 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	arg_error(void)
{
	write(2, "Wrong number of arguments\n", 26);
}

void	digit_error(void)
{
	write(2, "All arguments must be positive digits\n", 38);
}

void	long_error(void)
{
	write(2, "Please keep your args within int range\n", 39);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	verif_args(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 5 && ac != 6)
		return (arg_error(), 0);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (digit_error(), 0);
			j++;
		}
		if (ft_pos_atoi(av[i]) == -1)
			return (long_error(), 0);
		i++;
	}
	return (1);
}
