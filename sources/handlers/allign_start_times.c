/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allign_start_times.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:40:01 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 18:40:08 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	allign_start_times(time_t start_time)
{
	while (get_time_in_ms() < start_time)
		continue ;
}
