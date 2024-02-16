#include "philo.h"

bool can_join_thread(pthread_t thread)
{
    if (pthread_join(thread, NULL) != SUCCESS)
		return (false);
	return (true);
}

