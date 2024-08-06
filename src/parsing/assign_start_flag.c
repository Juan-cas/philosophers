/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_start_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:35:16 by juan-cas          #+#    #+#             */
/*   Updated: 2024/08/06 14:00:56 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../philosophers.h"

void assign_start_flag(t_control *control, t_soft *philo)
{
	int i;

	i = -1;
	while (++i < philo->total_philos)
	{
		philo[i].ready = control->start_flag;
	}
}