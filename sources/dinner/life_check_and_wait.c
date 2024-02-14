#include "philo.h"

void life_check_and_wait(t_philo *philo, time_t duration)
{
  bool should_stop;
  time_t time_to_wait_for;

  time_to_wait_for = get_time_in_ms() + duration;
  
  while (get_time_in_ms() < time_to_wait_for)
  {
    should_stop = (check_stop_condition_safely(&philo->dinner->stop_mutex, &philo->dinner->stop) == true);
    if (should_stop)
      return ;
    usleep(100);
  }
}

