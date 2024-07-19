/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:40:13 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/19 20:19:34 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static void lets_sleep(int count, t_philo *lego)
{
	printf("i am %d and im going to sleep for the %d time\n", lego->id + 1, count);
	ft_usleep(400);
}

static void lets_think(int count, t_philo *lego)
{
	printf("i am %d and im thinking for the %d time\n", lego->id + 1, count);
}

static void lets_eat(int count, t_philo *lego)
{
	if (lego->id == 0) {
		pthread_mutex_lock(lego->left_fork);
		pthread_mutex_lock(lego->right_fork);
	}
	else
	{
		pthread_mutex_lock(lego->right_fork);
		pthread_mutex_lock(lego->left_fork);
	}
	printf("i ate %d times and im philo #%d\n", count, lego->id);
	pthread_mutex_unlock(lego->right_fork);
	pthread_mutex_unlock(lego->left_fork);
}

void *routine(void *pointer)
{
	int i = 0;
	t_philo *philo_num = pointer;
	while (1)
	{
		lets_eat(i + 1, philo_num);
		lets_think(i + 1, philo_num);
		lets_sleep(i + 1, philo_num);
		i++;
		if (i == philo_num->num_times_to_eat)
			break ;
	}
	return (0);
}
