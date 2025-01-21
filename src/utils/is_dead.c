/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:15:07 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/21 22:11:32 by juan-cas         ###   ########.fr       */
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
	else
	{
		pthread_mutex_unlock(control->flag);
		return (0);
	}
}
