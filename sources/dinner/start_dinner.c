#include "philo.h"

void *philo_routine(void *arg)
{
  unsigned int i;
  t_philo *philo;

  philo = (t_philo *)arg;
  i = 0;
  while (i < philo->dinner->rules.min_meals)
  {
    printf("I am philo %d\n", philo->id);
    i++;
  }
  return (NULL);
}

void start_dinner(t_dinner *dinner)
{
  int i;

  i = 0;
  dinner->start_time = get_time_in_ms();
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
