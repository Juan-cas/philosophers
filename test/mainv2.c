/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainv2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:32:44 by juan-cas          #+#    #+#             */
/*   Updated: 2024/06/17 20:17:45 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef pthread_mutex_t t_mutex;

typedef struct s_soft
{
	pthread_t philo;
	int count;
	int id;
	int total_philos;
	t_mutex *right_forks;
	t_mutex *left_forks;
	t_mutex *forks;
}	t_soft;

//static void table_clear(t_mutex *fork)
//{
//	pthread_mutex_destroy(fork);
//}

static void lets_add_forks(t_soft *lego, int id, t_mutex *forks)
{
	if (id == 0)
	{
		lego[id].left_forks = &forks[lego->total_philos - 1];
		lego[id].right_forks = &forks[id];
	}
	else if (id > 0 && id != lego->total_philos - 1)
	{
		lego[id].left_forks = &forks[id - 1];
		lego[id].right_forks = &forks[id];
	}
	else if (id == lego->total_philos - 1)
	{
		lego[id].left_forks = &forks[id - 1];
		lego[id].right_forks = &forks[0];
	}
}


static void lets_sleep(int count, int id)
{
	printf("i am %d and im going to sleep for the %d time\n", id, count + 1);
	usleep(400);
}

static void lets_think(int count, int id)
{
	printf("i am %d and im thinking for the %d time\n", id, count + 1);
	usleep(500);
}

static void lets_eat(int count, int id, t_soft *lego)
{
	if (id % 2 == 0)
		usleep(1);
	printf("philosopher %d is waiting to grab the right fork\n", id);
	pthread_mutex_lock(lego[id].right_forks);
	printf("i am philo #%d and i grabbed the right fork\n", id);
	printf("philosopher %d is waiting to grab the left fork\n", id);
	pthread_mutex_lock(lego[id].left_forks);
	printf("i am philo #%d and i grabbed the left fork\n", id);
	printf("oh god i am eating for the %d time and im thread #%d\n", count + 1, id);
	pthread_mutex_unlock(lego[id].left_forks);
	printf("i am philo #%d and i dropped the right fork\n", id);
	pthread_mutex_unlock(lego[id].right_forks);
	printf("i am philo #%d and i dropped the left fork\n", id);
}


void *routine(void *pointer)
{
	int i = 0;
	t_soft *lego = pointer;
	int count = lego->count;
	while (count--)
	{
		lets_eat(i, lego->id, lego);
		lets_think(i, lego->id);
		lets_sleep(i, lego->id);
		i++;
	}
	return (pointer);
}

int main (int argc, char **argv)
{
	if (argc < 2)
		return (1);

	t_soft lego[atoi(argv[1])];
	t_mutex	forks[atoi(argv[1])];

	int i = 0;
	int k = 0;

	while (i < atoi(argv[1]))
	{
		lego[i].id = i;
		lego[i].count = atoi(argv[2]);
		lego[i].total_philos = atoi(argv[1]);
		lego[i].forks = (t_mutex *) &forks;
		i++;
	}

	while (k < atoi(argv[1]))
	{
		pthread_mutex_init(&forks[k], NULL);
		k++;
	}

	k = -1;
	while (++k < atoi(argv[1]))
		lets_add_forks(&lego[k], lego[k].id, forks);

	int  create = -1;
	while (++create < atoi(argv[1]))
		pthread_create(&lego[create].philo, NULL, &routine, (void *)&lego[create]);

	printf("hola antes del join");
	int join = 0;
	while (join < atoi(argv[1])) {
		printf("entra aqui %d %s \n", join, argv[1]);
		pthread_join(lego[join++].philo, NULL);
	}
		printf("hola luego del join\n");
	int destroy = -1;
	while (++destroy < atoi(argv[1]))
		pthread_mutex_destroy(&forks[destroy]);
	printf("despues de destroy\n");
	return (0);

}