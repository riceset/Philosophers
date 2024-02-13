#include "philo.h"

void life_check_and_wait(t_philo *philo, time_t duration)
{
  time_t time_to_wait_for;

  time_to_wait_for = get_time_in_ms() + duration;
  
  (void)philo;
  while (get_time_in_ms() < time_to_wait_for)
  {
    //check if someone died
    //check the time
    usleep(100);
  }
}

