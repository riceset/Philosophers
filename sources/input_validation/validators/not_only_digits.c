#include "philo.h"

bool not_only_digits(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (!is_digit(str[i]))
      return (true);
    i++;
  }
  return (false);
}
