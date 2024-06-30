/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainv3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 04:01:17 by juan-cas          #+#    #+#             */
/*   Updated: 2024/06/18 04:03:17 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>



int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);
    int i = -1;

    while (argv[++i]);

    printf("the number of arguments in i = %d\n", i);

    return (0);
}