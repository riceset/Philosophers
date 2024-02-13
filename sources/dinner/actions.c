#include "philo.h"

void eat(t_philo *philo)
{
  take_forks(philo);
  print_philo_status(philo, EATING);
  life_check_and_wait(philo, philo->dinner->rules.dining_duration);
  release_forks(philo);
}

void rest(t_philo *philo)
{
  print_philo_status(philo, SLEEPING);
  life_check_and_wait(philo, philo->dinner->rules.rest_duration);
}

void think(t_philo *philo)
{
  print_philo_status(philo, THINKING);
}
