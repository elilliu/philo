/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:32:27 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/20 21:31:06 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef enum e_bool
{
	true,
	false
}				t_bool;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	t_bool			available;
}				t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				num;
	t_bool			alive;
	t_bool			thinking;
	int				meals;
	struct timeval	last_meal;
	t_fork			left_fork;
	t_fork			*right_fork;
}				t_philo;

typedef struct s_data
{
	t_bool			active;
	int				current;
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meals;
	struct timeval	start;
	t_philo			**philo;
	pthread_mutex_t	write;
	pthread_mutex_t	mutex;
}			t_data;

void	init_philos(t_data *data);
void	*routine(void *structure);
void	take_fork(int num);
void	eating(int num);
void	sleeping(int num);
void	thinking(int num);
void	death(int num);
long	ft_atoi(const char *nptr);
void	free_data(t_data *data);
void	data_init(t_data *data, int ac, char **av);
int		verif_args(int ac, char **av);
int		ft_isdigit(int c);
void	long_error(void);
void	digit_error(void);
void	arg_error(void);
long	elapsed_time(struct timeval start);

#endif
