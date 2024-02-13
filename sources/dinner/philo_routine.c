#include "philo.h"

void *philo_routine(void *arg)
{
  unsigned int i;
  t_philo *philo;

  philo = (t_philo *)arg;
  i = 0;
  while (i < philo->dinner->rules.min_meals)
  {
    eat(philo);
    rest(philo);
    think(philo);
    i++;
  }
  return (NULL);
}

