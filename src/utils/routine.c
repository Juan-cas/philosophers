/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:40:13 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/17 18:43:55 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static void	print_message(char *str, t_soft *philo, int flag)
{
	size_t	time;

	time = get_current_time() - philo->start_time;
	if (!is_philo_dead(philo->control) && flag == 0)
		printf("%zu %d %s\n", time, philo->id, str);
	if (!is_philo_dead(philo->control) && flag == 1)
	{
		printf("%zu %d has taken a fork\n", time, philo->id);
		printf("%zu %d has taken a fork\n", time, philo->id);
		printf("%zu %d has eaten\n", time, philo->id);
	}
}

static void	lets_sleep(t_soft *philo)
{
	print_message("is sleeping", philo, 0);
	ft_usleep(philo->time_to_sleep, philo);
}

static void	lets_think(t_soft *philo)
{
	check_health(philo);
	print_message("is thinking", philo, 0);
}

static void	lets_eat(t_soft *philo)
{
	while(1)
	{
		if (is_philo_dead(philo->control))
			break ;
		if (grab_forks(philo->l_status, philo->left_fork))
		{
			if(grab_forks(philo->r_status, philo->right_fork))
			{
				check_health(philo);
				print_message("eating", philo, 1);
				philo->last_meal = get_current_time();
				if (philo->times_to_eat > 0)
					philo->times_to_eat--;
				ft_usleep(philo->time_to_eat, philo);
				drop_forks(philo->r_status, philo->right_fork);
				drop_forks(philo->l_status, philo->left_fork);
				break ;
			}
		drop_forks(philo->l_status, philo->left_fork);
		}
		ft_usleep(5, philo);
	}
}

void	*routine(void *pointer)
{
	t_soft	*philo;

	philo = pointer;
	philo->start_time = get_current_time();
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
