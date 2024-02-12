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
