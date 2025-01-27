/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:50:51 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/27 04:26:57 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sig;
	int		result;
	char	*str1;

	str1 = (char *) str;
	i = 0;
	sig = 1;
	result = 0;
	while ((str1[i] >= 9 && str1[i] <= 13) || (str1[i] == ' '))
		i++;
	if (str1[i] == '-' || str1[i] == '+')
	{
		if (str1[i] == '-')
			sig = -1;
		i++;
	}
	while (str1[i] >= '0' && str1[i] <= '9')
	{
		result = result * 10 + str1[i] - '0';
		i++;
	}
	return (result * sig);
}

