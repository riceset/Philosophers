#include "philo.h"

//maybe move to another file
static bool guard_check_stop(t_dinner *dinner)
{
  bool stop;

  pthread_mutex_lock(&dinner->stop_mutex);
  stop = dinner->stop;
  pthread_mutex_unlock(&dinner->stop_mutex);
  return (stop);
}

void life_check_and_wait(t_philo *philo, time_t duration)
{
  time_t time_to_wait_for;

  time_to_wait_for = get_time_in_ms() + duration;
  
  while (get_time_in_ms() < time_to_wait_for)
  {
    if (guard_check_stop(philo->dinner) == true)
      return ;
    //check the time
    usleep(100);
  }
}

