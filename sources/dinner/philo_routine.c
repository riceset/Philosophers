#include "philo.h"

static bool guard_check_stop(t_dinner *dinner)
{
  bool stop;

  pthread_mutex_lock(&dinner->stop_mutex);
  stop = dinner->stop;
  pthread_mutex_unlock(&dinner->stop_mutex);
  return (stop);
}

void *philo_routine(void *arg)
{
  t_philo *philo;

  philo = (t_philo *)arg;

  while (guard_check_stop(philo->dinner) == false)
  {
    eat(philo);
    rest(philo);
    think(philo);
  }
  print_philo_status(philo, DEAD);
  return (NULL);
}

