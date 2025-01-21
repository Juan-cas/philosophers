/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_assemble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:24:21 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/21 22:21:55 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void philosophers_assemble(t_soft *philo)
{
    while (1)
    {
        pthread_mutex_lock(philo->control->start_flag);
        philo->control->simulation_ready++;
        if (philo->control->simulation_ready == philo->total_philos)
        {
            philo->control->simulation_ready = 1;
        }
        if (philo->control->simulation_ready == 1)
        {
            pthread_mutex_unlock(philo->control->start_flag);
            break ;
        }
        pthread_mutex_unlock(philo->control->start_flag);
    }
}
