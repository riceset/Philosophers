#include "philo.h"

void *philo_routine(void *arg)
{
  t_philo *philo;

  philo = (t_philo *)arg;
  (void) philo;
  return (NULL);
}

void start_dinner(t_dinner *dinner)
{
  int i;

  i = 0;
  while (i < dinner->rules.philo_count)
  {
    if (pthread_create(&dinner->philos[i].thread, NULL, philo_routine, &dinner->philos[i]) != SUCCESS)
    {
      report_and_set_error(dinner, ERR_THREAD_CREATE, MSG_THREAD_CREATE);
      return ;
    }
    i++;
  }
}
