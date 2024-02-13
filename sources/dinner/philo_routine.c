#include "philo.h"

void life_check_and_wait_for(t_philo *philo, time_t duration)
{
  time_t time_to_wait_for;

  time_to_wait_for = get_time_in_ms() + duration;
  
  (void)philo;
  while (get_time_in_ms() < time_to_wait_for)
  {
    //check if someone died
    usleep(1000);
  }
}

void eat(t_philo *philo)
{
  (void) philo;
}

void rest(t_philo *philo)
{
  (void) philo;
}
void think(t_philo *philo)
{
  (void) philo;
}

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

