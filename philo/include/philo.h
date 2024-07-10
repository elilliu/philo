/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:32:27 by elilliu           #+#    #+#             */
/*   Updated: 2024/07/10 20:46:07 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_t	thread;
	int			num;
	int			die;
	int			eat;
	int			sleep;
	int			meals;
	int			left_fork;
	int			right_fork;
}		t_philo;

typedef struct s_data
{
	int				nb_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nb_of_meals;
	int				current;
	t_philo			*philo;
	pthread_mutex_t	mutex;
}	t_data;

void	take_fork(int num);
void	eating(int num);
void	sleeping(int num);
void	thinking(int num);
void	death(int num);
long	ft_atoi(const char *nptr);

#endif
