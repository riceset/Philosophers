#include "philo.h"

void *philo_routine(void *arg)
{
  t_philo *philo;

  philo = (t_philo *)arg;

  while (philo->dinner->stop == false)
  {
    eat(philo);
    rest(philo);
    think(philo);
  }
  print_philo_status(philo, DEAD);
  return (NULL);
}

