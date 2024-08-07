/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:41:13 by juan-cas          #+#    #+#             */
/*   Updated: 2024/08/06 19:25:52 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int ft_usleep(size_t miliseconds, t_soft *philo)
{
	size_t start;

	start = get_current_time();
	while ((get_current_time() - start) < miliseconds)
	{
		check_health(philo);
		usleep(500);
		pthread_mutex_lock(philo->control->flag);
		if(philo->control->death == 1)
		{
			pthread_mutex_unlock(philo->control->flag);
			break ;
		}
		pthread_mutex_unlock(philo->control->flag);
	}
	return (0);
}