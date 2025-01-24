/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:41:13 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/22 00:19:21 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	ft_usleep(size_t milliseconds, t_soft *philo)
{
	size_t	start;
	size_t	current;

	start = get_current_time();
	while (1)
	{
		current = get_current_time();
		if ((current - start) >= milliseconds)
			break;
		check_health(philo);
		if (is_philo_dead(philo->control))
			break;
		usleep(1000); // Sleep for a short interval to reduce CPU usage
	}
	return (0);
}
