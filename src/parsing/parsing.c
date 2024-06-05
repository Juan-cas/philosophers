/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:37:50 by juan-cas          #+#    #+#             */
/*   Updated: 2024/06/05 20:40:40 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

static int check_num_philos(char *str)
{
	if (ft_atol(str) >  200)
		return (1);
	return (0);
}

static int ft_is_plus(char character)
{
	if (character == '+')
		return (1);
	return (0);
}

int args_parser(char **argv)
{
	int i;
	int j;
	long comparer;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isalnum(argv[i][j]) || !ft_is_plus(argv[i][j]))
				return(param_error(i));
		}
	}
	i = 0;
	if (check_num_philos(argv[1]))
		return (param_error(1));
	while (argv[++i])
	{
		comparer = ft_atol(argv[i]);
		if (comparer > INT_MAX || comparer < INT_MIN || comparer <= 0)
			return (param_error(i));
	}
	return (0);
}