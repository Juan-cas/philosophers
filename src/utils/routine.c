/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:40:13 by juan-cas          #+#    #+#             */
/*   Updated: 2024/08/06 23:02:18 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"


static void	print_message(char *str, t_soft *philo, int flag)
{
	size_t	time;


	pthread_mutex_lock(philo->control->talk);
	if (!is_philo_dead(philo->control) && flag == 0)
	{
		time = get_current_time() - philo->start_time;
		printf("%zu %d %s\n", time, philo->id, str);
	}
	else if (!is_philo_dead(philo->control) && flag == 1)
	{
		time = get_current_time() - philo->start_time;
		printf("%zu %d has taken a fork\n", time, philo->id);
		printf("%zu %d has taken a fork\n", time, philo->id);
		printf("%zu %d has eaten\n", time, philo->id);
	}
	pthread_mutex_unlock(philo->control->talk);
}

static void lets_sleep(t_soft *philo)
{
	print_message("is sleeping", philo, 0);
	ft_usleep(philo->time_to_sleep, philo);
}
static void lets_think(t_soft *philo)
{
	check_health(philo);
	print_message("is thinking", philo, 0);
}

static void lets_eat(t_soft *philo)
{
	while(can_i_grab_forks(philo))
		usleep(100);
	check_health(philo);
	if (!is_philo_dead(philo->control))
	{
		print_message("eating", philo, 1);
		ft_usleep(philo->time_to_eat, philo);
		philo->last_meal = get_current_time();
		if (philo->times_to_eat > 0)
			philo->times_to_eat--;
		drop_forks(philo);
	}
}


void *routine(void *pointer)
{
	t_soft *philo = pointer;

	philosophers_assemble(philo);

	if (philo->id % 2 == 0)
		usleep(200);
	philo->start_time = get_current_time();
	philo->last_meal = get_current_time();
	while (1)
	{
		lets_eat(philo);
		lets_think(philo);
		lets_sleep(philo);
		if (philo->times_to_eat == 0)
			break ;
		if (is_philo_dead(philo->control))
			break ;
	}
	return (0);
}
