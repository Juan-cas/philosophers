/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:30:12 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/24 12:15:05 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static void preparation_for_simulation(t_control *control, t_soft *information)
{

}

void philo_initiation(int argc, char **argv)
{
	t_soft information[ft_atoi(argv[1])];
	t_mutex	forks[ft_atoi(argv[1])];
	t_control control;
	int i;

	i = 0;

	init_control(&control, information);
	init_philos(&control, information, argv, argc);
	lets_add_forks(&control, control.forks);
	init_mutexes(&control);
	preparation_for_simulation(&control, information);
}