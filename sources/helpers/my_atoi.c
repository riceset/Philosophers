#include "philo.h"

int my_atoi(const char *str)
{
  long long res;

  res = 0;
  while (*str != '\0')
  {
    res = res * 10 + (*str - '0');
    if (res > INT_MAX)
      return (ERR_ATOI);
    str++;
  }
  return ((int)(res));
}
