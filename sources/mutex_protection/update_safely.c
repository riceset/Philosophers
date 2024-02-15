#include "philo.h"

void update_end_condition_safely(pthread_mutex_t *mutex, bool *end_flag, bool new_value)
{
  pthread_mutex_lock(mutex);
  *end_flag = new_value;
  pthread_mutex_unlock(mutex);
}

void update_times_eaten_safely(pthread_mutex_t *mutex, unsigned int *times_eaten, unsigned int new_value)
{
  pthread_mutex_lock(mutex);
  *times_eaten = new_value;
  pthread_mutex_unlock(mutex);
}

void update_last_meal_time_safely(pthread_mutex_t *mutex, time_t *last_meal_time, time_t new_value)
{
  pthread_mutex_lock(mutex);
  *last_meal_time = new_value;
  pthread_mutex_unlock(mutex);
}
