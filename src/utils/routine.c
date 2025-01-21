/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:40:13 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/21 23:52:50 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	print_message(char *str, t_soft *philo, int flag)
{
	long	time;

	pthread_mutex_lock(philo->control->talk);
	pthread_mutex_lock(philo->control->start_flag);
	time = get_current_time() - philo->control->start_time;
	pthread_mutex_unlock(philo->control->start_flag);
	if (flag == 2)
	{
		printf("%ld %d %s\n", time, philo->id, str);
		return ;
	}
	if (is_philo_dead(philo->control))
	{
		pthread_mutex_unlock(philo->control->talk);
		return ;
	}
	if (flag == 0)
		printf("%ld %d %s\n", time, philo->id, str);
	if (flag == 1)
	{
		printf("%ld %d has taken a fork\n", time, philo->id);
		printf("%ld %d has taken a fork\n", time, philo->id);
		printf("%ld %d has eaten\n", time, philo->id);
	}
	pthread_mutex_unlock(philo->control->talk);
}

static void	lets_sleep(t_soft *philo)
{
	check_health(philo);
	print_message("is sleeping", philo, 0);
	ft_usleep(philo->time_to_sleep, philo);
	print_message("is thinking", philo, 0);
	check_health(philo);
}

static void	lets_eat(t_soft *philo)
{
	while (1)
	{
		if (is_philo_dead(philo->control))
			break ;
		if (grab_forks(philo->l_status, philo->left_fork))
		{
			check_health(philo);
			if (grab_forks(philo->r_status, philo->right_fork))
			{
				check_health(philo);
				print_message("eating", philo, 1);
				philo->last_meal = get_current_time();
				ft_usleep(philo->time_to_eat, philo);
				if (philo->times_to_eat > 0)
					philo->times_to_eat--;
				drop_forks(philo->r_status, philo->right_fork);
				drop_forks(philo->l_status, philo->left_fork);
				break ;
			}
			drop_forks(philo->l_status, philo->left_fork);
		}
		usleep(1000);
	}
}

void	*routine(void *pointer)
{
	t_soft	*philo;

	philo = pointer;
	philosophers_assemble(philo);
	if (philo->id % 2 == 0)
		usleep(200);
	pthread_mutex_lock(philo->control->start_flag);
	philo->control->start_time = get_current_time();
	philo->last_meal = philo->control->start_time;
	pthread_mutex_unlock(philo->control->start_flag);
	while (1)
	{
		check_health(philo);
		lets_eat(philo);
		check_health(philo);
		lets_sleep(philo);
		if (philo->times_to_eat == 0 || is_philo_dead(philo->control))
			break ;
	}
	return (0);
}
