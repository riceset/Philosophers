#include "philo.h"

bool should_terminate(t_dinner *dinner)
{
  pthread_mutex_lock(&dinner->stop_mutex);
  if (dinner->stop == false)
  {
    pthread_mutex_unlock(&dinner->stop_mutex);
    return (true);
  }
  else
  {
    pthread_mutex_unlock(&dinner->stop_mutex);
    return (false);
  }
}

void *philo_routine(void *arg)
{
  t_philo *philo;

  philo = (t_philo *)arg;

  while (should_terminate(philo->dinner))
  {
    eat(philo);
    rest(philo);
    think(philo);
  }
  print_philo_status(philo, DEAD);
  return (NULL);
}

