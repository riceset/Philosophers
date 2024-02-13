#include "philo.h"

static bool philosopher_is_left_handed(t_philo *philo)
{
  return (philo->id % 2);
}

static void assign_left_fork_first(t_philo *philo)
{
  int left_fork = philo->id;
  int right_fork = (philo->id + 1) % philo->dinner->rules.philo_count;

  philo->forks[0] = left_fork;
  philo->forks[1] = right_fork;
}

static void assign_right_fork_first(t_philo *philo)
{
  int right_fork = (philo->id + 1) % philo->dinner->rules.philo_count;
  int left_fork = (philo->id == 0) ? philo->dinner->rules.philo_count - 1 : philo->id - 1;
  philo->forks[0] = right_fork;
  philo->forks[1] = left_fork;
}

void assign_forks(t_philo *philo)
{
  if (philosopher_is_left_handed(philo))
    assign_left_fork_first(philo);
  else
    assign_right_fork_first(philo);
}
