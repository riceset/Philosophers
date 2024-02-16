/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:41:14 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:41:20 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	release_left_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->dinner->forks[philo->forks[0]]);
}

static void	release_right_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->dinner->forks[philo->forks[1]]);
}

void	release_forks(t_philo *philo)
{
	release_left_fork(philo);
	release_right_fork(philo);
}
