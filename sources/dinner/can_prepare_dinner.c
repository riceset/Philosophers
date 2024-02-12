#include "philo.h"

bool can_prepare_dinner(t_dinner *dinner, int argc, char **argv)
{
  set_dinner_start_time(dinner);
  set_dinner_status(dinner);
  if (correct_input(dinner, argc, argv))
  {
    set_dinner_rules(dinner, argc, argv);
    if (can_initialize_forks(dinner))
    {
      initialize_philosophers(dinner);
      return (true);
    }
  }
  return (false);
}