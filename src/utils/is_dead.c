/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:15:07 by juan-cas          #+#    #+#             */
/*   Updated: 2024/08/06 20:18:40 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int is_philo_dead(t_control *control)
{
	pthread_mutex_lock(control->flag);
	if (control->death == 1)
		return (pthread_mutex_unlock(control->flag), 1);
	else
		return(pthread_mutex_unlock(control->flag), 0);
}