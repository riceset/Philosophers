/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_initialize_print_mutex.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:38:21 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:38:23 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	can_initialize_print_mutex(t_dinner *dinner)
{
	if (pthread_mutex_init(&dinner->print_mutex, NULL) != SUCCESS)
	{
		report_and_set_error(dinner, ERR_MUTEX_INIT, MSG_MUTEX_INIT);
		return (false);
	}
	return (true);
}
