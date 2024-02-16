/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_and_set_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:39:33 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:39:35 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	report_and_set_error(t_dinner *dinner, int code, char *msg)
{
	pthread_mutex_lock(&dinner->print_mutex);
	printf("philo: %s\n", msg);
	dinner->exit_status = code;
	pthread_mutex_unlock(&dinner->print_mutex);
}
