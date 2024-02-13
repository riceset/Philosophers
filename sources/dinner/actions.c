#include "philo.h"

void eat(t_philo *philo)
{
  take_forks(philo);
  print_philo_status(philo, EATING);
  life_check_and_wait(philo, philo->dinner->rules.dining_duration);

  pthread_mutex_lock(&philo->last_meal_time_mutex);
  philo->last_meal_time = get_time_in_ms();
  pthread_mutex_unlock(&philo->last_meal_time_mutex);

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
