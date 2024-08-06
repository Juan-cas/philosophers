/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_assemble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:24:21 by juan-cas          #+#    #+#             */
/*   Updated: 2024/08/06 20:25:16 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void philosophers_assemble(t_soft *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->ready);
		if (philo->id == philo->total_philos - 1)
			philo->control->simulation_ready = 1;
		if (philo->control->simulation_ready == 1)
		{
			pthread_mutex_unlock(philo->ready);
			break ;
		}
		pthread_mutex_unlock(philo->ready);
	}
}