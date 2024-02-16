/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:41:04 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:41:05 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	rest(t_philo *philo)
{
	print_philo_status(philo, SLEEPING);
	life_check_and_wait(philo, philo->dinner->rules.rest_duration);
}
