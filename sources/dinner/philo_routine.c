#include "philo.h"

void print_in_required_format(t_philo *philo, char *action)
{
  printf("%ld %d %s\n", get_time_in_ms() - philo->dinner->start_time, philo->id, action);
}

void print_philo_status(t_philo *philo, t_philo_status status)
{
	if (status == DEAD)
		print_in_required_format(philo, MSG_DEAD);
	else if (status == EATING)
		print_in_required_format(philo, MSG_EATING);
	else if (status == SLEEPING)
		print_in_required_format(philo, MSG_SLEEPING);
	else if (status == THINKING)
		print_in_required_format(philo, MSG_THINKING);
	else if (status == TAKING_FORK)
		print_in_required_format(philo, MSG_TAKING_FORK);
}

void life_check_and_wait_for(t_philo *philo, time_t duration)
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

void eat(t_philo *philo)
{
  print_philo_status(philo, EATING);
  life_check_and_wait_for(philo, philo->dinner->rules.dining_duration);
}

void rest(t_philo *philo)
{
  print_philo_status(philo, SLEEPING);
  life_check_and_wait_for(philo, philo->dinner->rules.rest_duration);
}
void think(t_philo *philo)
{
  print_philo_status(philo, THINKING);
}

void *philo_routine(void *arg)
{
  unsigned int i;
  t_philo *philo;

  philo = (t_philo *)arg;
  i = 0;
  while (i < philo->dinner->rules.min_meals)
  {
    eat(philo);
    rest(philo);
    think(philo);
    i++;
  }
  return (NULL);
}

