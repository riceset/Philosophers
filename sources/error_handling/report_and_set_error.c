#include "philo.h"

void report_and_set_error(t_dinner *dinner, int code, char *msg)
{
  printf("philo: %s\n", msg);
  dinner->exit_status = code;
}
