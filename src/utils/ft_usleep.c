/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:41:13 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/21 23:48:23 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

int	ft_usleep(size_t miliseconds, t_soft *philo)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < miliseconds)
	{
		check_health(philo);
		if (is_philo_dead(philo->control))
			break ;
		usleep(1000);
	}
	return (0);
}
