#include "philo.h"

void set_dinner_start_time(t_dinner *dinner)
{
  dinner->rules.start_time = get_time_in_ms();
}
