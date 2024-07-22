/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:32:27 by elilliu           #+#    #+#             */
/*   Updated: 2024/07/14 18:02:18 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	int				nb;
}		t_mutex;

typedef struct s_philo
{
	pthread_t	thread;
	int			num;
	int			die;
	time_t		last_meal;
	t_mutex		left_fork;
	t_mutex		*right_fork;
	t_mutex		*write;
}		t_philo;

typedef struct s_data
{
	int		nb_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_of_meals;
	t_philo	*philo;
	t_mutex	write;
}	t_data;

void	take_fork(int num);
void	eating(int num);
void	sleeping(int num);
void	thinking(int num);
void	death(int num);
long	ft_atoi(const char *nptr);

#endif
