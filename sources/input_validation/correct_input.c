#include "philo.h"

bool correct_input(int argc, char **argv) {
  int i;
  int curr_arg;

  if (incorrect_num_of_args(argc))
    return (false);

  i = 1;
  while (i < argc) {
    if (not_only_digits(argv[i]))
      return (false);
    curr_arg = my_atoi(argv[i]);
    if (curr_arg == ERR_ATOI)
      return (false);
    if (wrong_num_philos(i, curr_arg))
      return (false);
    i++;
  }
  return (true);
}
