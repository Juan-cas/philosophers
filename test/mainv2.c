/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainv2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:32:44 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/23 13:18:28 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "../lib/libft/libft.h"
#include <time.h>




void last_destroy(t_control *control)
{
	pthread_mutex_destroy(control->flag);
	pthread_mutex_destroy(control->talk);
	pthread_mutex_destroy(control->meal);
}




int main (int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);

	init_control(&control, information);

	k = -1;

	int  create = -1;
	while (++create < number)
        pthread_create(&information[create].philo, NULL, &routine, (void *)&information[create]);

    int join = -1;
	while (++join < number)
        pthread_join(information[join].philo, NULL);

    int destroy = -1;
	while (++destroy < number)
        pthread_mutex_destroy(&forks[destroy]);
	last_destroy(&control);

	return (free(control.talk), free(control.flag), free(control.meal), 0);
}