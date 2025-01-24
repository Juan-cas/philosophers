/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:15:07 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/22 00:15:08 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	is_philo_dead(t_control *control)
{
	pthread_mutex_lock(control->flag);
	if (control->death == 1)
	{
		pthread_mutex_unlock(control->flag);
		return (1);
	}
	pthread_mutex_unlock(control->flag);
	return (0);
}
