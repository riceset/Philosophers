#include "philo.h"

void *philo_routine(void *arg)
{
  t_philo *philo;

  philo = (t_philo *)arg;

  while (!check_stop_condition_safely(&philo->dinner->stop_mutex, &philo->dinner->stop))
  {
    eat(philo);
    rest(philo);
    think(philo);
  }
  print_philo_status(philo, DEAD);
  return (NULL);
}

