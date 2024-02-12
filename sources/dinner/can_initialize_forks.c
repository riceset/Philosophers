#include "philo.h"

static void handle_mutex_init_failure(t_dinner *dinner, int i)
{
  while (i > 0)
  {
    i--;
    pthread_mutex_destroy(&dinner->forks[i]);
  }
}

bool can_initialize_forks(t_dinner *dinner)
{
  int i;

  i = 0;
  while (i < dinner->rules.philo_count)
  {
    if (pthread_mutex_init(&dinner->forks[i], NULL) != SUCCESS)
    {
      handle_mutex_init_failure(dinner,i);
      report_and_set_error(dinner, ERR_MUTEX_INIT, MSG_MUTEX_INIT);
      return (false);
    }
    i++;
  }
  return (true);
}
