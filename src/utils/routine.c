/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:40:13 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/22 00:15:08 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static void	print_message(char *str, t_soft *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->control->talk);
	if (is_philo_dead(philo->control))
	{
		pthread_mutex_unlock(philo->control->talk);
		return ;
	}
	time = get_current_time() - philo->start_time;
	if (!ft_strncmp(str, "fork", 4))
		printf("\033[0;33m%zu %d has taken a fork\n", time, philo->id);
	if (!ft_strncmp(str, "eat", 3))
		printf("\033[0;32m%zu %d is eating\n", time, philo->id);
	if (!ft_strncmp(str, "sleep", 5))
		printf("\033[0;36m%zu %d is sleeping\n", time, philo->id);
	if (!ft_strncmp(str, "think", 5))
		printf("\033[0;35m%zu %d is thinking\n", time, philo->id);
	if (!ft_strncmp(str, "dead", 4))
	{
		printf("\033[0;31m%zu %d died\n", time, philo->id);
	}
	pthread_mutex_unlock(philo->control->talk);
}

static void	lets_sleep(t_soft *philo)
{
	print_message("sleep", philo);
	ft_usleep(philo->time_to_sleep, philo);
}

static void	lets_think(t_soft *philo)
{
	check_health(philo);
	print_message("think", philo);
}

static void	lets_eat(t_soft *philo)
{
	while (1)
	{
		if (is_philo_dead(philo->control))
			break;
		check_health(philo);
		if (grab_forks(philo->l_status, philo->left_fork))
		{
			check_health(philo);
			if (grab_forks(philo->r_status, philo->right_fork))
			{
				print_message("fork", philo);
				print_message("fork", philo);
				print_message("eat", philo);
				philo->last_meal = get_current_time();
				ft_usleep(philo->time_to_eat, philo);
				if (philo->times_to_eat > 0)
					philo->times_to_eat--;
				drop_forks(philo->r_status, philo->right_fork);
				drop_forks(philo->l_status, philo->left_fork);
				break;
			}
			drop_forks(philo->l_status, philo->left_fork);
		}
			ft_usleep(1, philo);
	}
}

void	*routine(void *pointer)
{
	t_soft	*philo;

	philo = pointer;
	philosophers_assemble(philo);
	philo->start_time = get_current_time();
	usleep(100);
	philo->last_meal = get_current_time();
	while (1)
	{
		lets_eat(philo);
		lets_think(philo);
		lets_sleep(philo);
		if (philo->times_to_eat == 0 || is_philo_dead(philo->control))
			break ;
	}
	return (0);
}
