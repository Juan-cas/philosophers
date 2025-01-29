#include "../../philosophers.h"

void check_health(t_philo *philo)
{
	size_t last_meal_check;

	last_meal_check = get_current_time() - philo->last_meal;
	if (last_meal_check > philo->time_to_die)
		talk(5, philo->start_time, philo);
}

int philo_dead(t_table *table, int flag)
{
	int status;

	pthread_mutex_lock(table->flag);
	if (table->death == 0)
	{
		if (flag == 1)
			table->death = 1;
	}
	status = table->death;
	pthread_mutex_unlock(table->flag);
	return (status);
}