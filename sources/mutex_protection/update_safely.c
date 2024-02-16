/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_safely.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:40:33 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 15:08:54 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_stop_condition_safely(pthread_mutex_t *mutex, bool *end_flag,
		bool new_value)
{
	pthread_mutex_lock(mutex);
	*end_flag = new_value;
	pthread_mutex_unlock(mutex);
}

void	update_times_eaten_safely(pthread_mutex_t *mutex,
		unsigned int *times_eaten, unsigned int new_value)
{
	pthread_mutex_lock(mutex);
	*times_eaten = new_value;
	pthread_mutex_unlock(mutex);
}

void	update_last_meal_time_safely(pthread_mutex_t *mutex,
		time_t *last_meal_time, time_t new_value)
{
	pthread_mutex_lock(mutex);
	*last_meal_time = new_value;
	pthread_mutex_unlock(mutex);
}
