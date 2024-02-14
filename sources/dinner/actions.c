#include "philo.h"

void eat(t_philo *philo)
{
  take_forks(philo);
  print_philo_status(philo, EATING);
  life_check_and_wait(philo, philo->dinner->rules.dining_duration);

  update_last_meal_time_safely(&philo->last_meal_time_mutex, &philo->last_meal_time, get_time_in_ms());

  release_forks(philo);
}

void rest(t_philo *philo)
{
  print_philo_status(philo, SLEEPING);
  life_check_and_wait(philo, philo->dinner->rules.rest_duration);
}

time_t calculate_thinking_duration(t_philo *philo)
{
  time_t lifespan;
  time_t thinking_duration;
  time_t fasting_duration;
  time_t dining_duration;

  lifespan = philo->dinner->rules.lifespan;
  fasting_duration = get_time_in_ms() - check_last_meal_time_safely(&philo->last_meal_time_mutex, &philo->last_meal_time);
  dining_duration = philo->dinner->rules.dining_duration;
  thinking_duration = (lifespan - fasting_duration - dining_duration) / 2;

  if (thinking_duration <= 0)
    thinking_duration = 1;
  if (thinking_duration > 600)
    thinking_duration = 200;

  return (thinking_duration);
}

void think(t_philo *philo)
{
  print_philo_status(philo, THINKING);
  life_check_and_wait(philo, calculate_thinking_duration(philo));
}
