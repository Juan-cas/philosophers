/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:57:56 by juan-cas          #+#    #+#             */
/*   Updated: 2024/06/05 23:31:51 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void simulation_start(p_info  *table)
{

}

void philosophers(char **argv)
{
	t_program	table;
	t_philo 	philos[ft_atoi(argv[1])];
	t_mutex		forks[ft_atoi(argv[1])];

	init_structs(&table, philos, argv, forks);
	simulation_start(&table);
}