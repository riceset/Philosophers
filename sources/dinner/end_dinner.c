#include "philo.h"

void end_dinner(t_dinner *dinner)
{
  int i;

  i = 0;
  while (i < dinner->rules.philo_count)
  {

    if (!can_join_thread(dinner->philos[i].thread))
    {
      report_and_set_error(dinner, ERR_THREAD_JOIN, MSG_THREAD_JOIN);
      return ;
    }
    i++;
  }
  if (dinner->rules.philo_count > 1)
  {
    if (!can_join_thread(dinner->supervisor))
    {
      report_and_set_error(dinner, ERR_THREAD_JOIN, MSG_THREAD_JOIN);
      return ;
    }
  }
}
