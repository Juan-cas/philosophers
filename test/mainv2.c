/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainv2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:32:44 by juan-cas          #+#    #+#             */
/*   Updated: 2024/06/30 21:00:41 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


typedef struct s_control t_control;
typedef pthread_mutex_t t_mutex;

typedef struct s_soft
{
	pthread_t philo;
	int count;
	int id;
	int total_philos;
	t_mutex *right_fork;
	t_mutex *left_fork;
	t_mutex *forks;
//    t_control *mind_control;
}	t_soft;

typedef struct s_control
{
    int     control;
    t_soft  *philos;
}   t_control;

static void lets_add_forks(t_control *control, int id, t_mutex *forks)
{
	if (id == 0)
	{
		control->philos[id].left_fork = &forks[control->philos->total_philos - 1];
		control->philos[id].right_fork = &forks[id];
	}
	else
	{
		control->philos[id].left_fork = &forks[id - 1];
		control->philos[id].right_fork = &forks[id];
	}

}


static void lets_sleep(int count, t_soft *lego)
{
	printf("i am %d and im going to sleep for the %d time\n", lego->id + 1, count);
	usleep(400);
}

static void lets_think(int count, t_soft *lego)
{
	printf("i am %d and im thinking for the %d time\n", lego->id + 1, count);
}

static void lets_eat(int count, t_soft *lego)
{
    if (lego->id == 0) {
        pthread_mutex_lock(lego->left_fork);
        pthread_mutex_lock(lego->right_fork);
    }
    else
    {
        pthread_mutex_lock(lego->right_fork);
        printf("i am philo #%d and i grabbed the right fork\n", lego->id);
        pthread_mutex_lock(lego->left_fork);
        printf("i am philo #%d and i grabbed the left fork\n", lego->id);
    }
    printf("i ate %d times and im philo #%d\n", count, lego->id);
    pthread_mutex_unlock(lego->right_fork);
    pthread_mutex_unlock(lego->left_fork);
}


void *routine(void *pointer)
{
	int i = 0;
	t_soft *lego = pointer;
	while (1)
	{
		lets_eat(i + 1, lego);
		lets_think(i + 1, lego);
		lets_sleep(i + 1, lego);
		i++;
        if (i == lego->count)
            break ;
	}
	return (0);
}

static void init_control(t_control *control, t_soft *lego, int numb_phil)
{
    control->philos = lego;
    control->control = numb_phil;
}

int main (int argc, char **argv)
{
	if (argc < 2)
		return (1);

	t_soft lego[atoi(argv[1])];
	t_mutex	forks[atoi(argv[1])];
    t_control control;

    init_control(&control, lego, atoi(argv[1]));
	int i = 0;
	int k = -1;
    int number = atoi(argv[1]);

	while (i < number)
	{
		lego[i].id = i;
		lego[i].count = atoi(argv[2]);
		lego[i].total_philos = number;
		i++;
	}
	while (++k < number)
    {
        if (pthread_mutex_init(&forks[k], NULL) == -1)
            return (1);
    }

	k = -1;
	while (++k < number)
		lets_add_forks(&control, lego[k].id, forks);

	int  create = -1;
	while (++create < number)
        pthread_create(&lego[create].philo, NULL, &routine, (void *)&lego[create]);

    int join = -1;
	while (++join < number)
        pthread_join(lego[join].philo, NULL);

    int destroy = -1;
	while (++destroy < number)
        pthread_mutex_destroy(&forks[destroy]);
	return (0);
}