/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 05:34:39 by juan-cas          #+#    #+#             */
/*   Updated: 2024/06/01 14:54:00 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static void init_table_and_forks(t_program *table)
{
	table->dead_flag = 0;
	
}

void init_structs(t_program *table, t_philo *philo, char **argv)
{
	init_table(table);
}