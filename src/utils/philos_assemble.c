/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_assemble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:24:21 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/22 00:15:08 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	philosophers_assemble(t_soft *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->control->start_flag);
		if (philo->id == philo->total_philos - 1)
			philo->control->simulation_ready = 1;
		if (philo->control->simulation_ready == 1)
		{
			pthread_mutex_unlock(philo->control->start_flag);
			break ;
		}
		pthread_mutex_unlock(philo->control->start_flag);
		usleep(100); // Sleep for a short interval to reduce CPU usage
	}
}
