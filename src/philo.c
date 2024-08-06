/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:57:56 by juan-cas          #+#    #+#             */
/*   Updated: 2024/08/06 18:16:06 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void philo_cleaner(t_soft *philo, int total)
{
	int	i;

	i = -1;
	while (++i < total)
		pthread_join(philo[i].philo, NULL);
}

static void philo_creator(t_soft *philo, int total)
{
	int i;

	i = -1;
	while (++i < total)
	{
		pthread_create(&philo[i].philo, NULL, routine, (void *)&philo[i]);
	}
}

static void	simulation_start(t_soft *philo, t_control *control)
{
	int	total;

	total = philo->total_philos;

	philo_creator(philo, total);
	philo_cleaner(philo, total);
	cleaner_of_forks(control, total);
	mind_control_check(control, 3);
	clear_start_flags(control);
}

void philosophers(int argc, char **argv)
{
	t_control	control;
	t_soft		philo[ft_atoi(argv[1])];
	t_mutex		forks[ft_atoi(argv[1])];
	t_mutex		simulation_flag;


	init_control(&control, forks);
	init_philos(&control, philo, argv, argc);
	control.philos = philo;
	control.start_flag = &simulation_flag;
	init_mutexes(&control);
	init_tags(&control.fork_tags, argv);
	lets_add_forks(philo, forks, control.fork_tags);
	assign_start_flag(&control, philo);
	simulation_start(philo, &control);
}