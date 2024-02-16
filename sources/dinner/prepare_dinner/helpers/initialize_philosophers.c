/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_philosophers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:38:31 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:39:14 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_philosophers(t_dinner *dinner)
{
	int	i;

	i = 0;
	while (i < dinner->rules.philo_count)
	{
		dinner->philos[i].id = i + 1;
		dinner->philos[i].times_eaten = 0;
		dinner->philos[i].dinner = dinner;
		assign_forks(&dinner->philos[i]);
		dinner->philos[i].last_meal_time = get_time_in_ms();
		pthread_mutex_init(&dinner->philos[i].times_eaten_mutex, NULL);
		pthread_mutex_init(&dinner->philos[i].last_meal_time_mutex, NULL);
		i++;
	}
}
