/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:42:30 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 14:42:38 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lonely_philosopher(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->forks[philo->forks[0]]);
	print_philo_status(philo, TAKING_FORK);
	life_check_and_wait(philo, philo->dinner->rules.lifespan);
	print_philo_status(philo, DEAD);
	pthread_mutex_unlock(&philo->dinner->forks[philo->forks[0]]);
	return (NULL);
}
