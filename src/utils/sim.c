#include "../../philosophers.h"

void talk(int flag, size_t s_time, t_philo *philo)
{
	size_t c_time;

	c_time = get_current_time() - s_time;
	pthread_mutex_lock(philo->table->talk);
	if (philo_dead(philo->table))
	{
		pthread_mutex_unlock(philo->table->talk);
		return ;
	}
	if (flag == 1)
		printf("%zu philo %d took a fork\n", c_time, philo->id + 1);
	if (flag == 2)
		printf("%zu philo %d is eating\n", c_time, philo->id + 1);
	if (flag == 3)
		printf("%zu philo %d is sleeping\n", c_time, philo->id + 1);
	if (flag == 4)
		printf("%zu philo %d is thinking\n", c_time, philo->id + 1);
	if (flag == 5)
	{
		printf("%zu philo %d has died\n", c_time, philo->id + 1);
		philo_just_died(philo->table);	
	}
	pthread_mutex_unlock(philo->table->talk);
}

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;
	size_t	current;

	start = get_current_time();
	while (1)
	{
		current = get_current_time();
		if ((current - start) >= milliseconds)
			break;
		check_health(philo);
		if (philo_dead(philo->table))
			break;
		usleep(200);
	}
	return (0);
}


static void sleep_think(t_philo *philo)
{
	talk(3, philo->start_time, philo);
	ft_usleep(philo->time_to_sleep, philo);
	talk(4, philo->start_time, philo);
}

static void eat(t_philo *philo)
{
	while(1)
	{
		check_health(philo);
		if (philo_dead(philo->table))
			return;
		if (pick_fork(philo->l_status, philo->left_fork))
		{
			if (pick_fork(philo->r_status, philo->right_fork))
			{
				talk(1, philo->start_time, philo);
				talk(1, philo->start_time, philo);
				talk(2, philo->start_time, philo);
				philo->last_meal = get_current_time();
				ft_usleep(philo->time_to_eat, philo);
				drop_fork(philo->l_status, philo->left_fork);
				drop_fork(philo->r_status, philo->right_fork);
				return ;
			}
			drop_fork(philo->l_status, philo->left_fork);
		}
		ft_usleep(1, philo);
	}
}

void *routine(void *philosopher)
{
	t_philo *philo;

	philo = (t_philo *)philosopher;
	while(1)
	{
		check_health(philo);
		if (philo_dead(philo->table))
			break ;
		if (philo->times_to_eat == 0)
			break ;
		eat(philo);
		check_health(philo);
		sleep_think(philo);
	}
	return (0);
}