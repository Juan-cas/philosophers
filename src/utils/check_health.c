/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_health.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:33:40 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/17 18:23:48 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	check_health(t_soft *philo)
{
	size_t	last_meal;

	pthread_mutex_lock(philo->control->flag);
	last_meal = get_current_time() - philo->last_meal;
	if (last_meal > philo->time_to_die && philo->control->death == 0)
	{
		printf("%zu %d has died\n", get_current_time() - philo->start_time,
			philo->id);
		philo->control->death = 1;
	}
	pthread_mutex_unlock(philo->control->flag);
}
