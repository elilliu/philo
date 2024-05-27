/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:32:27 by elilliu           #+#    #+#             */
/*   Updated: 2024/05/27 20:13:22 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>

typedef struct s_philo
{
    int num;
    int die;
    int eat;
    int sleep;
    int meals;
}           t_philo;

int	    main(int ac, char **av);
void    arg_error(void);
void	digit_error(void);
int		ft_isdigit(int c);
long	ft_atoi(const char *nptr);
int		verif_args(int ac, char **av);

#endif
