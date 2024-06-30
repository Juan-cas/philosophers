/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:32:30 by juan-cas          #+#    #+#             */
/*   Updated: 2024/06/18 03:55:20 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include "./lib/libft/libft.h"

typedef pthread_mutex_t t_mutex;
typedef struct t_info p_info;
typedef struct p_philo p_philo;

# define RST	"\033[0" //reset to default color
# define RED	"\033[1;31m" //bold red
# define C		"\033[1;36m" //Bold cyan
# define G		"\033[1;32m" //bold green
# define Y		"\033[1;33m" //bold yellow
# define B		"\033[1;34m" //bold Blue
# define M		"\033[1;35m" //bold magenta
# define W		"\033[1;37m" //bold white

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;


typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

//main function
void philosophers(char **argv);

//errors
int param_error(int i);

//parsing
int args_parser(char **argv);

//utils
long	ft_atol(const char *str);
size_t get_current_time();
int ft_usleep(size_t miliseconds);
void init_structs(t_program *table, t_philo *philo, char **argv, t_mutex *forks);

#endif