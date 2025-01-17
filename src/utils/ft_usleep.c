/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:41:13 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/17 18:52:36 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	ft_usleep(size_t miliseconds, t_soft *philo)
{
	size_t	start;

	pthread_mutex_lock(philo->control->meal);
	start = get_current_time();
	pthread_mutex_unlock(philo->control->meal);
	while ((get_current_time() - start) < miliseconds)
	{
		check_health(philo);
		if (is_philo_dead(philo->control))
			break ;
		usleep(500);
	}
	return (0);
}
