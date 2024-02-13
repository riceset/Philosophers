#include "philo.h"

void end_dinner(t_dinner *dinner)
{
  int i;

  i = 0;
  while (i < dinner->rules.philo_count)
  {
    if (pthread_join(dinner->philos[i].thread, NULL) != SUCCESS)
    {
      report_and_set_error(dinner, ERR_THREAD_JOIN, MSG_THREAD_JOIN);
      return ;
    }
    i++;
  }
  if (dinner->rules.philo_count > 1)
  {
    if (pthread_join(dinner->supervisor, NULL) != SUCCESS)
    {
      report_and_set_error(dinner, ERR_THREAD_JOIN, MSG_THREAD_JOIN);
      return ;
    }
  }
}
