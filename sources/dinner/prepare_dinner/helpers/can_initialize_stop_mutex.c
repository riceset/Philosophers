#include "philo.h"

bool can_initialize_stop_mutex(t_dinner *dinner)
{
  dinner->stop = false;
  if (pthread_mutex_init(&dinner->stop_mutex, NULL) != SUCCESS)
  {
    report_and_set_error(dinner, ERR_MUTEX_INIT, MSG_MUTEX_INIT);
    return (false);
  }
  return (true);
}

