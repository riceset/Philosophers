#include "philo.h"

bool correct_input(t_dinner *dinner, int argc, char **argv) {
  int i;
  int curr_arg;

  if (incorrect_num_of_args(argc))
  {
    report_and_set_error(dinner, ERR_NUM_ARGS, MSG_NUM_ARGS);
    return (false);
  }

  i = 1;
  while (i < argc) {
    if (not_only_digits(argv[i]))
    {
      report_and_set_error(dinner, ERR_NOT_ONLY_DIGITS, MSG_NOT_ONLY_DIGITS);
      return (false);
    }
    curr_arg = my_atoi(argv[i]);
    if (curr_arg == ERR_ATOI)
    {
      report_and_set_error(dinner, ERR_ATOI, MSG_ATOI);
      return (false);
    }
    if (wrong_num_philos(i, curr_arg))
    {
      report_and_set_error(dinner, ERR_NUM_PHILOS, MSG_NUM_PHILOS);
      return (false);
    }
    i++;
  }
  return (true);
}
