/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:41:01 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 18:33:31 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	take_forks(philo);
	print_philo_status(philo, EATING);
	life_check_and_wait(philo, philo->dinner->rules.dining_duration);
	update_times_eaten_safely(&philo->times_eaten_mutex, &philo->times_eaten, philo->times_eaten + 1);
	update_last_meal_time_safely(&philo->last_meal_time_mutex,
		&philo->last_meal_time, get_time_in_ms());
	release_forks(philo);
}
