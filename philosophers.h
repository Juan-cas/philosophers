/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:32:30 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/28 21:20:37 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include "./lib/libft/libft.h"

# define RST	"\033[0" //reset to default color
# define RED	"\033[1;31m" //bold red
# define C		"\033[1;36m" //Bold cyan
# define G		"\033[1;32m" //bold green
# define Y		"\033[1;33m" //bold yellow
# define B		"\033[1;34m" //bold Blue
# define M		"\033[1;35m" //bold magenta
# define W		"\033[1;37m" //bold white

typedef struct s_control t_control;
typedef pthread_mutex_t t_mutex;

typedef struct s_soft
{
	pthread_t	philo;
	int			times_to_eat;
	int			id;
	int			total_philos;
	int			start_time;
	int			time_to_sleep;
	size_t		time_to_die;
	size_t		last_meal;
	size_t		time_to_eat;
	t_mutex		*right_fork;
	t_mutex		*left_fork;
	t_control	*control;
}	t_soft;

typedef struct s_control
{
	int     control;
	int		death;
	t_soft	*philos;
	t_mutex	*talk;
	t_mutex	*flag;
	t_mutex *meal;
	t_mutex *forks;
}   t_control;

//main function
void	philosophers(int argc, char **argv);

//errors
int		param_error(int i);

//parsing
int		args_parser(char **argv);

//utils
long	ft_atol(const char *str);
void	lets_add_forks(t_control *control, t_mutex *forks);
void	init_control(t_control *control);
size_t	ft_atost(const char *str);
void	*routine(void *pointer);
size_t	get_current_time();
int		init_mutexes(t_control *control);
int		cleaner_of_forks(t_control *control, int order);
int		ft_usleep(size_t miliseconds);
void	init_philos(t_control *control, t_soft *information, char **argv, int argc);
int		mind_control_check(int order, t_control *control);
void	free_the_mind(t_control *control);
int		check_health(t_soft *information);
#endif