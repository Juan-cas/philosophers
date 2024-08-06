/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:34:18 by juan-cas          #+#    #+#             */
/*   Updated: 2024/08/06 13:59:57 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void clear_start_flags(t_control *control)
{
		pthread_mutex_destroy(control->start_flag);
}

void free_the_mind(t_control *control)
{

	free(control->flag);
	free(control->talk);
	free(control->fork_tags);
}

int	mind_control_check(t_control *control, int order)
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