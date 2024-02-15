#include "philo.h"

void rest(t_philo *philo)
{
  print_philo_status(philo, SLEEPING);
  life_check_and_wait(philo, philo->dinner->rules.rest_duration);
}
