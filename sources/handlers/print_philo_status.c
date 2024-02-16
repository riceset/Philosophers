/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:39:29 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:39:31 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_in_required_format(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->dinner->print_mutex);
	printf("%ld %d %s\n", get_time_in_ms() - philo->dinner->rules.start_time,
		philo->id, action);
	pthread_mutex_unlock(&philo->dinner->print_mutex);
}

void	print_philo_status(t_philo *philo, t_philo_status status)
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
