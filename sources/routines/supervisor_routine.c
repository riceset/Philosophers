/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:40:50 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 18:37:17 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor_routine(void *arg)
{
	int			i;
	t_dinner	*dinner;

	dinner = (t_dinner *)arg;
	while (true)
	{
		i = 0;
		while (i < dinner->rules.philo_count)
		{
			pthread_mutex_lock(&dinner->philos[i].last_meal_time_mutex);
			if (get_time_in_ms()
				- dinner->philos[i].last_meal_time >= dinner->rules.lifespan)
			{
				print_philo_status(&dinner->philos[i], DEAD);
				update_stop_condition_safely(&dinner->stop_mutex, &dinner->stop,
					true);
				pthread_mutex_unlock(&dinner->philos[i].last_meal_time_mutex);
				return (NULL);
			}
			if (dinner->rules.min_meals != (unsigned int)MIN_MEALS_NOT_SET)
				if (check_times_eaten_safely(&dinner->philos[i].times_eaten_mutex,
						&dinner->philos[i].times_eaten) > dinner->rules.min_meals)
				{
					update_stop_condition_safely(&dinner->stop_mutex, &dinner->stop,
						true);
					pthread_mutex_unlock(&dinner->philos[i].last_meal_time_mutex);
					return (NULL);
				}
			pthread_mutex_unlock(&dinner->philos[i].last_meal_time_mutex);
			i++;
		}
	}
	return (NULL);
}
