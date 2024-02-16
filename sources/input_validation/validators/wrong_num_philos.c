/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_num_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:40:02 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 14:57:09 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	wrong_num(int i, int curr_arg, t_dinner *dinner)
{
	if (i == 1 && !(0 < curr_arg && curr_arg <= PHILO_MAX))
	{
		report_and_set_error(dinner, ERR_NUM_PHILOS, MSG_NUM_PHILOS);
		return (true);
	}
	else if ((2 <= i && i <= 5) && curr_arg < 1)
	{
		report_and_set_error(dinner, ERR_NUM, MSG_NUM);
		return (true);
	}
	return (false);
}
