#include "../../philosophers.h"

void	philo_not_talking(t_soft *philo)
{
	pthread_mutex_lock(philo->control->talk);
	philo->control->talking = 0;
	pthread_mutex_unlock(philo->control->talk);

}

int	philo_talking(t_soft *philo)
{
pthread_mutex_lock(philo->control->talk);
	if (philo->control->talking == 0)
	{
		philo->control->talking = 1;
		pthread_mutex_unlock(philo->control->talk);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(philo->control->talk);
		return (0);
	}
}