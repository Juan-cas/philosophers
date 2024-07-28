/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:24:40 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/28 18:40:41 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

void lets_add_forks(t_control *control, t_mutex *forks)
{
	int	i;
	i = -1;
	while (++i < control->philos->total_philos)
	{
		if (i == 0)
		{
			control->philos[i].left_fork = &forks[control->philos->total_philos - 1];
			control->philos[i].right_fork = &forks[i];
		}
		else
		{
			control->philos[i].left_fork = &forks[i - 1];
			control->philos[i].right_fork = &forks[i];
		}
	}
}

void init_philos(t_control *control, t_soft *information, char **argv, int argc)
{
	int	i;
	int number;

	i = 0;
	number = ft_atoi(argv[1]);
	while (++i <= number)
	{
		information[i].times_to_eat = 0;
		information[i].id = i;
		information[i].total_philos = number;
		information[i].time_to_die = ft_atoi(argv[2]);
		information[i].time_to_eat = ft_atost(argv[3]);
		information[i].time_to_sleep = ft_atoi(argv[4]);
		information[i].control = control;
		if (argc == 6)
			information[i].times_to_eat = ft_atoi(argv[5]);
	}
}

void init_control(t_control *control)
{
	control->flag = malloc(sizeof(t_mutex));
	control->talk = malloc(sizeof(t_mutex));
	control->meal = malloc(sizeof(t_mutex));
	pthread_mutex_init(control->talk, NULL);
	pthread_mutex_init(control->flag, NULL);
	pthread_mutex_init(control->meal, NULL);
	control->death = 0;
}
