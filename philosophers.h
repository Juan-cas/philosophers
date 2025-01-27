/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:32:30 by juan-cas          #+#    #+#             */
/*   Updated: 2025/01/27 09:02:01 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "./lib/libft/libft.h"
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define RST "\033[0"     // reset to default color
# define RED "\033[1;31m" // bold red
# define C "\033[1;36m"   // Bold cyan
# define G "\033[1;32m"   // bold green
# define Y "\033[1;33m"   // bold yellow
# define B "\033[1;34m"   // bold Blue
# define M "\033[1;35m"   // bold magenta
# define W "\033[1;37m"   // bold white

typedef struct s_table	t_table;
typedef struct timeval	t_time;
typedef pthread_mutex_t		t_mutex;

typedef struct s_philosopher
{
	pthread_t				phi;
	int						id;
	int						time_to_sleep;
	int						times_to_eat;
	int						time_to_eat;
	t_mutex					*right_fork;
	int						*r_status;
	t_mutex					*left_fork;
	int						*l_status;
	size_t					time_to_die;
	size_t					start_time;
	size_t					last_meal;
	t_table					*table;
}							t_philo;

typedef struct s_table
{
	int						death;
	int						*fork_tags;
	int						talking;
	t_philo					**philos;
	t_mutex					*talk;
	t_mutex					*flag;
	t_mutex					*forks;
}							t_table;

// main function

// errors

// parsing
int		lets_parse(int argc, char **argv);

// utils
int		philos(int argc, char **argv);
void	*routine(void *philo);
void	init_sim(int nb, t_table *table);
size_t	get_current_time(void);
void	check_health(t_philo *philo);
int		philo_dead(t_table *table);
void	philo_just_died(t_table *table);
long	ft_atol(const char *str);
void	talk(int flag, size_t s_time, t_philo *philo);
void	clean_sim(int nb, t_table *table);
int		pick_fork(int *fork, t_mutex *mutex);
void	drop_fork(int *fork, t_mutex *mutex);

#endif