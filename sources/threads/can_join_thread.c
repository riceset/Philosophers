/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_join_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:41:33 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:41:36 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	can_join_thread(pthread_t thread)
{
	if (pthread_join(thread, NULL) != SUCCESS)
		return (false);
	return (true);
}
