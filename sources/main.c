#include "philo.h"

int main(int argc, char **argv)
{
  t_dinner dinner;

  if (can_prepare_dinner(&dinner, argc, argv))
  {
    start_dinner(&dinner);
    end_dinner(&dinner);
  }

  return (dinner.exit_status);
}
