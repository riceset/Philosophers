/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:40:50 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 18:51:34 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	died_from_starvation(t_dinner *dinner, int i)
{
	if (get_time_in_ms()
		- dinner->philos[i].last_meal_time >= dinner->rules.lifespan)
	{
		print_philo_status(&dinner->philos[i], DEAD);
		update_stop_condition_safely(&dinner->stop_mutex, &dinner->stop, true);
		pthread_mutex_unlock(&dinner->philos[i].last_meal_time_mutex);
		return (true);
	}
	return (false);
}

bool	philosopher_is_full(t_dinner *dinner, int i)
{
	if (dinner->rules.min_meals != (unsigned int)MIN_MEALS_NOT_SET)
	{
		if (check_times_eaten_safely(&dinner->philos[i].times_eaten_mutex,
				&dinner->philos[i].times_eaten) > dinner->rules.min_meals)
		{
			update_stop_condition_safely(&dinner->stop_mutex, &dinner->stop,
				true);
			pthread_mutex_unlock(&dinner->philos[i].last_meal_time_mutex);
			return (true);
		}
	}
	return (false);
}

void	*supervisor_routine(void *arg)
{
	int			i;
	t_dinner	*dinner;

	dinner = (t_dinner *)arg;
	allign_start_times(dinner->rules.start_time);
	while (true)
	{
		i = 0;
		while (i < dinner->rules.philo_count)
		{
			pthread_mutex_lock(&dinner->philos[i].last_meal_time_mutex);
			if (died_from_starvation(dinner, i))
				return (NULL);
			if (philosopher_is_full(dinner, i))
				return (NULL);
			pthread_mutex_unlock(&dinner->philos[i].last_meal_time_mutex);
			i++;
		}
	}
	return (NULL);
}
