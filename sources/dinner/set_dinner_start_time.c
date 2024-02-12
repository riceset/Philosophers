#include "philo.h"

void set_dinner_start_time(t_dinner *dinner)
{
  dinner->start_time = get_time_in_ms();
}
