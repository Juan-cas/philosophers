#include "../../philosophers.h"

static void clean_philos(int nb, t_table *table)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		pthread_join(table->philos[i]->phi, NULL);
		free(table->philos[i]);
	}
		free(table->philos);
}

void clean_sim(int nb, t_table *table)
{
	int	i;

	i = -1;
	clean_philos(nb, table);
	while (++i < nb)
	{
		pthread_mutex_destroy(&table->forks[i]);
		// free(&table->forks[i]);
		// free(&table->fork_tags[i]);
	}
	free(table->fork_tags);
	free(table->forks);
	pthread_mutex_destroy(table->talk);
	pthread_mutex_destroy(table->flag);
	free(table->talk);
	free(table->flag);
}

void init_sim(int nb, t_table *table)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		if (pthread_create(&table->philos[i]->phi, NULL,
			routine, table->philos[i]) != 0) // Pass the correct philosopher pointer
		{
			while (--i > 0)
				pthread_join(table->philos[i]->phi, NULL);
			perror("thread initiation failed\n");	
			return ;
		}
	}
}