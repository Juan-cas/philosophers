/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:34:18 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/28 21:20:30 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void free_the_mind(t_control *control)
{

	free(control->flag);
	free(control->talk);
	free(control->meal);
}

int	mind_control_check(int order, t_control *control)
{
	if (order == 1)
	{
		pthread_mutex_destroy(control->flag);
		return (free_the_mind(control), 1);
	}
	if (order == 2)
	{
		pthread_mutex_destroy(control->flag);
		pthread_mutex_destroy(control->talk);
		return (free_the_mind(control), 1);
	}
	if (order == 3)
	{
		pthread_mutex_destroy(control->flag);
		pthread_mutex_destroy(control->talk);
		pthread_mutex_destroy(control->meal);
		return (free_the_mind(control), 1);
	}
	return (0);
}

int cleaner_of_forks(t_control *control, int order)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < order)
	{
		pthread_mutex_destroy(&control->forks[j++]);
	}
	if (j != 0)
		return (1);
	return (0);
}