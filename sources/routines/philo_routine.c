/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:40:46 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:40:49 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!check_stop_condition_safely(&philo->dinner->stop_mutex,
			&philo->dinner->stop))
	{
		eat(philo);
		rest(philo);
		think(philo);
	}
	print_philo_status(philo, DEAD);
	return (NULL);
}
