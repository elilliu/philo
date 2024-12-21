/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:32:27 by elilliu           #+#    #+#             */
/*   Updated: 2024/12/21 01:22:23 by elilliu@stu      ###   ########.fr       */
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
	struct s_philo	*prev;
	pthread_t		thread;
	int				num;
	int				die;
	time_t			last_meal;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	struct s_philo	*next;
}				t_philo;

typedef struct s_data
{
	int				current;
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meals;
	t_philo			*philo;
	pthread_mutex_t	write;
	pthread_mutex_t	mutex;
}			t_data;

void	init_philos(t_data *data);
void	init_philo(t_philo *philo);
void	*routine(void *structure);
void	take_fork(int num);
void	eating(int num);
void	sleeping(int num);
void	thinking(int num);
void	death(int num);
long	ft_pos_atoi(const char *nptr);
void	free_data(t_data *data);
void	data_init(t_data *data, int ac, char **av);
int		verif_args(int ac, char **av);
int		ft_isdigit(int c);
void	long_error(void);
void	digit_error(void);
void	arg_error(void);

#endif
