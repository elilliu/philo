/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu@student.42.fr <elilliu>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:32:27 by elilliu           #+#    #+#             */
/*   Updated: 2025/01/22 19:07:42 by elilliu@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	bool			available;
}				t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				num;
	bool			thinking;
	int				meals;
	struct timeval	last_meal;
	t_fork			left_fork;
	t_fork			*right_fork;
}				t_philo;

typedef struct s_data
{
	bool			active;
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

void	data_init(t_data *data, int ac, char **av);
void	init_philos(t_data *data);
void	*routine(void *structure);
int		ft_eat(t_data *data, t_philo *philo);
int		ft_sleep(t_data *data, t_philo *philo);
void	ft_think(t_data *data, t_philo *philo);
void	ft_die(t_data *data, t_philo *philo);
long	ft_atoi(const char *nptr);
void	free_data(t_data *data);
int		verif_args(int ac, char **av);
int		ft_isdigit(int c);
void	long_error(void);
void	digit_error(void);
void	arg_error(void);
long	elapsed_time(struct timeval start);

#endif
