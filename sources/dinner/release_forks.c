#include "philo.h"

static void release_left_fork(t_philo *philo)
{
  pthread_mutex_unlock(&philo->dinner->forks[philo->forks[0]]);
}

static void release_right_fork(t_philo *philo)
{
  pthread_mutex_unlock(&philo->dinner->forks[philo->forks[1]]);
}

void release_forks(t_philo *philo)
{
  release_left_fork(philo);
  release_right_fork(philo);
}
