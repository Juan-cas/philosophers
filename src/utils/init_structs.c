/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 05:34:39 by juan-cas          #+#    #+#             */
/*   Updated: 2024/06/08 04:54:08 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static t_philo init_philo(char **argv, t_program *table, t_mutex *forks, int i)
{
	t_philo philosopher;
	int i;

	i = -1;
	while (argv[++i]);
	philosopher.id = i;
	philosopher.eating = 0;
	philosopher.meals_eaten = 0;
	philosopher.last_meal = 0;
	philosopher.time_to_die = ft_atoi(argv[2]);
	philosopher.time_to_eat = ft_atoi(argv[3]);
	philosopher.time_to_sleep = ft_atoi(argv[4]);
	philosopher.start_time = get_current_time();
	philosopher.num_of_philos = ft_atoi(argv[1]);
	if (i == 5)
		philosopher.num_times_to_eat = ft_atoi(argv[5]);
	philosopher.dead = &table->dead_flag;


}

static void init_t_and_f(t_program *table, int philo_numb,
						 t_philo *philos, t_mutex *forks)
{
	int i;

	i = 0;
	table->dead_flag = 0;
	table->philos = philos;
	pthread_mutex_init(&table->write_lock, NULL);
	pthread_mutex_init(&table->dead_lock, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
	while(i < philo_numb)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	table->philos = philos;
}

void init_structs(t_program *table, t_philo *philo, char **argv, t_mutex *forks)
{
	int i;

	i = 0;
	init_t_and_f(table, ft_atoi(argv[1]),philo, forks);
	while (i < ft_atoi(argv[1]))
	{
		philo[i] = init_philo(argv, table, forks, i);
	}
}