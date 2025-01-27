#include "../../philosophers.h"

void drop_fork(int *fork, t_mutex *mutex)
{
	pthread_mutex_lock(mutex);
	(*fork) = 0;
	pthread_mutex_unlock(mutex);
}

int pick_fork(int *fork, t_mutex *mutex)
{
	pthread_mutex_lock(mutex);
	if ((*fork) == 0)
	{
		(*fork) = 1;
		pthread_mutex_unlock(mutex);
		return (1);
	}
	pthread_mutex_unlock(mutex);
	return (0);
}