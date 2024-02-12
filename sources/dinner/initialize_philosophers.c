#include "philo.h"

void initialize_philosophers(t_dinner *dinner)
{
  int i;

  i = 0;
  while (i < dinner->rules.philo_count)
  {
    dinner->philos[i].id = i + 1;
    dinner->philos[i].dinner = dinner;
    i++;
  }
}
