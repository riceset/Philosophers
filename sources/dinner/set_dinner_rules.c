#include "philo.h"

void set_dinner_rules(t_dinner *dinner, int argc, char **argv)
{
  dinner->rules.philo_count = my_atoi(argv[1]);
  dinner->rules.lifespan = my_atoi(argv[2]);
  dinner->rules.dining_duration = my_atoi(argv[3]);
  dinner->rules.rest_duration = my_atoi(argv[4]);

  if (argc == 6)
    dinner->rules.min_meals = my_atoi(argv[5]);
  else
    dinner->rules.min_meals = MIN_MEALS_NOT_SET;
}
