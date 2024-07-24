/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:41:26 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/24 13:20:43 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"


static int	init_forks(t_control *control)
{
	int i;

	i = -1;
	while (++i < control->philos->total_philos)
	{
		if (pthread_mutex_init(&control->forks[i],NULL) != 0)
			return (i);
	}
	return (0);
}

static int control_mutexes(t_control *control)
{
	if (pthread_mutex_init(control->flag, NULL) != 0)
		return (1);
	if (pthread_mutex_init(control->talk, NULL) != 0)
		return (2);
	if (pthread_mutex_init(control->meal, NULL) != 0)
		return (3);
	return (0);
}


int init_mutexes(t_control *control)
{
	if (mind_control_check(control_mutexes(control), control))
		return (1);
	if (janitor_forks(init_forks(control), control))
	{
		mind_control_check(3, control);
		return (1);
	}

	return (0);
}