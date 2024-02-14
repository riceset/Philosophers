#include "philo.h"

static void print_in_required_format(t_philo *philo, char *action)
{
  printf("%ld %d %s\n", get_time_in_ms() - philo->dinner->rules.start_time, philo->id, action);
}

void print_philo_status(t_philo *philo, t_philo_status status)
{
	if (status == DEAD)
		print_in_required_format(philo, MSG_DEAD);
	else if (status == EATING)
		print_in_required_format(philo, MSG_EATING);
	else if (status == SLEEPING)
		print_in_required_format(philo, MSG_SLEEPING);
	else if (status == THINKING)
		print_in_required_format(philo, MSG_THINKING);
	else if (status == TAKING_FORK)
		print_in_required_format(philo, MSG_TAKING_FORK);
}

