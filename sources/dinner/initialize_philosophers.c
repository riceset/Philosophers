#include "philo.h"

void initialize_philosophers(t_dinner *dinner)
{
  int i;

  i = 0;
  while (i < dinner->rules.philo_count)
  {
    dinner->philos[i].id = i + 1;
    dinner->philos[i].times_eaten = 0;
    dinner->philos[i].dinner = dinner;
    assign_forks(&dinner->philos[i]);
    i++;
  }
}
