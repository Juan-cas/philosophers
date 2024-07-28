/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_health.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:33:40 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/25 18:14:27 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int check_health(t_soft *information)
{
	pthread_mutex_lock(information->control->flag);
	if (get_current_time() - information->last_meal >= information->time_to_die
		&& information->control->death == 0)
	{
		printf("%zu %d has died", get_current_time(), information->id + 1);
		information->control->death = 1;
		return(pthread_mutex_unlock(information->control->flag), 1);
	}
	pthread_mutex_unlock(information->control->flag);
	return (0);
}
