/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:40:13 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/28 18:45:39 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"


static void	print_message(char *str, t_soft *information)
{
	size_t	time;

	pthread_mutex_lock(information->control->talk);
	time = get_current_time() - information->start_time;
	if (information->control->death == 0)
		printf("%zu %d %s\n", time, information->id, str);
	pthread_mutex_unlock(information->control->talk);
}

static void lets_sleep(t_soft *information)
{
	check_health(information);
	if (information->control->death == 0)
	{
		print_message("is sleeping", information);
		ft_usleep(information->time_to_sleep);
	}
}

static void lets_think(t_soft *information)
{
	check_health(information);
	if (information->control->death == 0)
	{
		print_message("is thinking", information);
	}
}

static void lets_eat(t_soft *information)
{
	if (information->control->death == 0)
	{
		if (information->id == 0) {
			pthread_mutex_lock(information->left_fork);
			print_message("has taken a fork", information);
			pthread_mutex_lock(information->right_fork);
			print_message("has taken a fork", information);
		}
		else
		{
			pthread_mutex_lock(information->right_fork);
			print_message("has taken a fork", information);
			pthread_mutex_lock(information->left_fork);
			print_message("has taken a fork", information);
		}
		check_health(information);
		print_message("has eaten", information);
		pthread_mutex_lock(information->control->meal);
		information->last_meal = get_current_time();
		if (information->times_to_eat != -1)
			information->times_to_eat--;
		pthread_mutex_unlock(information->control->meal);
		ft_usleep(information->time_to_sleep);
		pthread_mutex_unlock(information->right_fork);
		pthread_mutex_unlock(information->left_fork);
	}
}


void *routine(void *pointer)
{
	t_soft *information = pointer;

	information->start_time = get_current_time();
	information->last_meal = get_current_time();
	while (1)
	{
		lets_eat(information);
		lets_think(information);
		lets_sleep(information);
		if (information->times_to_eat != -1)
		{
			if (information->times_to_eat == 0)
				break ;
		}
		if (information->control->death == 1)
			break ;
	}
	return (0);
}
