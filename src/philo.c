/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:57:56 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/28 21:13:09 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void philo_cleaner(t_soft *philos, int total)
{
	int	i;

	i = 0;
	while (++i < total)
		pthread_join(philos[i].philo, NULL);
}

static void philo_creator(t_soft *philos, int total)
{
	int i;

	i = -1;
	while (++i < total)
		pthread_create(&philos[i].philo, NULL, routine, (void *)&philos[i]);
}

static void	simulation_start(t_soft *philos, t_control *control)
{
	int	total;

	total = philos->total_philos;

	philo_creator(philos, total);
	philo_cleaner(philos, total);
	cleaner_of_forks(control, total);
	free_the_mind(control);

}

void philosophers(int argc, char **argv)
{
	t_control	control;
	t_soft		philos[ft_atoi(argv[1])];
	t_mutex		forks[ft_atoi(argv[1])];

	init_control(&control);
	init_philos(&control, philos, argv, argc);
	control.philos = philos;
	lets_add_forks(&control, forks);
	simulation_start(philos, &control);
}