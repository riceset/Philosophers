/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_initialize_stop_mutex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:38:24 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:38:26 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	can_initialize_stop_mutex(t_dinner *dinner)
{
	dinner->stop = false;
	if (pthread_mutex_init(&dinner->stop_mutex, NULL) != SUCCESS)
	{
		report_and_set_error(dinner, ERR_MUTEX_INIT, MSG_MUTEX_INIT);
		return (false);
	}
	return (true);
}
