/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:30:09 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/27 07:43:58 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (lets_parse(argc, argv))
			return (1);
		philos(argc, argv);
	}
	else
	{
		printf(RED "Error,\n" RST);
		printf(G "please check the number of arguments\n" RST);
		printf(G "#philos / time 2 die / time 2 eat / time to sleep " RST);
		printf(G "for infinite simulation or add number of times to eat\n" RST);
		printf(G "meaning 4 args for infinite and 5 for finite\n" RST);
	}
	return (0);
}
