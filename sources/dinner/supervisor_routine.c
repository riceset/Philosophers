#include "philo.h"

void *supervisor_routine(void *arg)
{
  int i;
  t_dinner *dinner;

  dinner = (t_dinner *)arg;

  while (true)
  {
    i = 0;
    while (i < dinner->rules.philo_count)
    {
      pthread_mutex_lock(&dinner->philos[i].last_meal_time_mutex);
      if (get_time_in_ms() - dinner->philos[i].last_meal_time >= dinner->rules.lifespan)
      {
          pthread_mutex_lock(&dinner->stop_mutex);
          dinner->stop = true;
          pthread_mutex_unlock(&dinner->stop_mutex);
        pthread_mutex_unlock(&dinner->philos[i].last_meal_time_mutex);
      }
      pthread_mutex_unlock(&dinner->philos[i].last_meal_time_mutex);
      i++;
    }
  }
  return (NULL);
}
