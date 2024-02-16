/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:41:16 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:41:17 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->forks[philo->forks[0]]);
	print_philo_status(philo, TAKING_FORK);
}

static void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->dinner->forks[philo->forks[1]]);
	print_philo_status(philo, TAKING_FORK);
}

void	take_forks(t_philo *philo)
{
	take_left_fork(philo);
	take_right_fork(philo);
}
