/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_health.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:33:40 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/17 20:10:42 by juan-cas         ###   ########.fr       */
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
		philo->control->death = 1;
	}
	pthread_mutex_unlock(philo->control->flag);

}
