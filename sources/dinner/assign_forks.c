#include "philo.h"

static bool philosopher_is_left_handed(t_philo *philo)
{
  return (philo->id % 2);
}

static void assign_left_fork_first(t_philo *philo)
{
  philo->forks[0] = philo->id;
  philo->forks[1] = (philo->id + 1) % philo->dinner->rules.philo_count;
}

static void assign_right_fork_first(t_philo *philo)
{
  philo->forks[1] = philo->id;
  philo->forks[0] = (philo->id + 1) % philo->dinner->rules.philo_count;
}

void assign_forks(t_philo *philo)
{
  if (philosopher_is_left_handed(philo))
    assign_left_fork_first(philo);
  else
    assign_right_fork_first(philo);
}
