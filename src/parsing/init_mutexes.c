/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:41:26 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/28 21:22:30 by juan-cas         ###   ########.fr       */
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
	return (-1);
}

static int control_mutexes(t_control *control)
{
	if (pthread_mutex_init(control->flag, NULL) != 0)
		return (1);
	if (pthread_mutex_init(control->talk, NULL) != 0)
		return (2);
	if (pthread_mutex_init(control->meal, NULL) != 0)
		return (3);
	return (-1);
}


int init_mutexes(t_control *control)
{
	int checker;

	checker = control_mutexes(control);
	if (checker != -1)
	{
		mind_control_check(checker, control);
		free_the_mind(control);
		return (1);
	}
	checker = init_forks(control);
	if (checker != -1)
	{
		cleaner_of_forks(control, checker);
		mind_control_check(3, control);
		free_the_mind(control);
		return (1);
	}

	return (0);
}