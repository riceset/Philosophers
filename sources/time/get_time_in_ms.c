#include "philo.h"

time_t get_time_in_ms(void)
{
  struct timeval tv;

  gettimeofday(&tv, NULL);
  return (s_to_ms(tv.tv_sec) + us_to_ms(tv.tv_usec));
}
