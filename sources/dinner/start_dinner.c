#include "philo.h"

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
