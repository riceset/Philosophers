#include "philo.h"

bool can_create_thread(pthread_t *thread, void *(*routine)(void *), void *arg)
{
    if (pthread_create(thread, NULL, routine, arg) != SUCCESS)
		return (false);
	return (true);
}
