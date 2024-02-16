/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_create_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:41:30 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:41:32 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	can_create_thread(pthread_t *thread, void *(*routine)(void *),
		void *arg)
{
	if (pthread_create(thread, NULL, routine, arg) != SUCCESS)
		return (false);
	return (true);
}
