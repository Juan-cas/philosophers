/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:45:19 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/17 18:16:10 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void	drop_forks(int *fork, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	(*fork) = 0;
	pthread_mutex_unlock(mutex);
}

int		grab_forks(int *fork, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	if ((*fork) == 0)
	{
		(*fork) = 1;
		pthread_mutex_unlock(mutex);
		return (1);
	}
	pthread_mutex_unlock(mutex);
	return (0);
}
