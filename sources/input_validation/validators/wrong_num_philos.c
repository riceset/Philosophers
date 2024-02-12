#include "philo.h"

bool wrong_num_philos(int i, int curr_arg)
{
  bool curr_arg_is_num_philos;
  bool not_between_constraints;

  curr_arg_is_num_philos = (i == 1);
  not_between_constraints = !(0 < curr_arg && curr_arg <= 250);

  if (curr_arg_is_num_philos && not_between_constraints)
    return (true);
  else
    return (false);
}
