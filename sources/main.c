#include "philo.h"

int main(int argc, char **argv)
{
  t_dinner dinner;

  if (correct_input(&dinner, argc, argv))
    can_prepare_dinner(&dinner, argc, argv);

  return (dinner.exit_status);
}
