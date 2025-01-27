#include "../../philosophers.h"

static void fill_forks(int nb, t_table *table, t_philo *philo)
{
	if (philo->id == nb - 1)
		philo->r_status = &table->fork_tags[0];
	else
		philo->r_status = &table->fork_tags[philo->id + 1];
	if (philo->id == 0)
		philo->l_status = &table->fork_tags[nb - 1];
	else
		philo->l_status = &table->fork_tags[philo->id - 1];
	if (philo->id == nb - 1)
		philo->right_fork = &table->forks[0];
	else
		philo->right_fork = &table->forks[philo->id + 1];
	if (philo->id == 0)
		philo->left_fork = &table->forks[nb - 1];
	else
		philo->left_fork = &table->forks[philo->id - 1];
}

static void init_philo(int ac, char **av, int nb, t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1; 
	while (++i < nb)
	{
		philo = ft_calloc(1, sizeof(t_philo));
		philo->id = i;
		philo->time_to_die = ft_atoi(av[2]);
		philo->time_to_eat = ft_atoi(av[3]);
		philo->time_to_sleep = ft_atoi(av[4]);
		if(ac == 6)
			philo->times_to_eat = ft_atoi(av[5]);
		else
			philo->times_to_eat = -1;
		philo->start_time = get_current_time();
		philo->last_meal = get_current_time();
		philo->table = table;
		table->philos[i] = philo;
		fill_forks(nb, table, philo);
	}
}

static int init_table(int ac, char **av, t_table *table)
{
	int	nb;
	int	i;

	i = -1;
	nb = ft_atoi(av[1]);
	table->fork_tags = ft_calloc(nb, sizeof(int));
	table->forks = ft_calloc(nb, sizeof(t_mutex));
	table->philos = ft_calloc(nb, sizeof(t_philo *));
	while (++i < nb)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			while(--i > 0)
				pthread_mutex_destroy(&table->forks[i]);
			perror("forks mutex init failed\n");
			return (-1);
		}
	}
	return (init_philo(ac, av, nb, table), 0);
}


int philos(int argc, char **argv)
{
	t_table *table;

	table = ft_calloc(1, sizeof(t_table));
	if (!table || init_table(argc, argv, table) < 0)
		return (-1);
	table->talk = ft_calloc(1, sizeof(t_mutex));
	table->flag = ft_calloc(1, sizeof(t_mutex));
	pthread_mutex_init(table->talk, NULL);
	pthread_mutex_init(table->flag, NULL);
	table->death = 0;
	init_sim(ft_atoi(argv[1]), table);
	clean_sim(ft_atoi(argv[1]), table);
	free(table);
	return (0);
}
