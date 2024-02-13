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

bool can_prepare_dinner(t_dinner *dinner, int argc, char **argv)
{
  set_dinner_start_time(dinner);
  set_dinner_status(dinner);
  if (correct_input(dinner, argc, argv))
  {
    set_dinner_rules(dinner, argc, argv);
    if (can_initialize_forks(dinner))
    {
      initialize_philosophers(dinner);
      if (can_initialize_stop_mutex(dinner))
        return (true);
    }
  }
  return (false);
}
