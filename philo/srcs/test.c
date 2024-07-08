/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:38:50 by elilliu           #+#    #+#             */
/*   Updated: 2024/07/08 14:51:25 by elilliu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*computation(void *add)
{
	long	*add_num;

	add_num = (long *)add;
	printf("Add: %ld\n", *add_num);
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;
	long		value1;
	long		value2;

	value1 = 1;
	value2 = 2;
	pthread_create(&thread1, NULL, computation, (void *) &value1);
	pthread_create(&thread2, NULL, computation, (void *) &value2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return (0);
}
