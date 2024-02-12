#include "philo.h"

bool can_convert_str_to_int(t_dinner *dinner, const char *str, int *res)
{
  long long n;

  n = 0;
  while (*str != '\0')
  {
    n = n * 10 + (*str - '0');
    if (n > INT_MAX)
    {
      report_and_set_error(dinner, ERR_ATOI, MSG_ATOI);
      return (false);
    }
    str++;
  }
  *res = n;
  return (true);
}

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
    if (!can_convert_str_to_int(dinner, argv[i], &curr_arg))
      return (false);
    if (wrong_num_philos(i, curr_arg))
    {
      report_and_set_error(dinner, ERR_NUM_PHILOS, MSG_NUM_PHILOS);
      return (false);
    }
    i++;
  }
  return (true);
}
