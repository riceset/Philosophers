/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:37:48 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 14:36:14 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dinner(t_dinner *dinner)
{
	int	i;

	i = 0;
	dinner->rules.start_time = get_time_in_ms();
	while (i < dinner->rules.philo_count)
	{
		if (!can_create_thread(&dinner->philos[i].thread, philo_routine,
				&dinner->philos[i]))
		{
			report_and_set_error(dinner, ERR_THREAD_CREATE, MSG_THREAD_CREATE);
			return ;
		}
		i++;
	}
	if (dinner->rules.philo_count > 1)
	{
		if (!can_create_thread(&dinner->supervisor, supervisor_routine, dinner))
		{
			report_and_set_error(dinner, ERR_THREAD_CREATE, MSG_THREAD_CREATE);
			return ;
		}
	}
}
