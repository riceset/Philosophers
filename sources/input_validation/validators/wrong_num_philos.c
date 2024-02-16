/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_num_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:40:02 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:49:08 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	wrong_num_philos(int i, int curr_arg, t_dinner *dinner)
{
	bool	curr_arg_is_num_philos;
	bool	not_between_constraints;

	curr_arg_is_num_philos = (i == 1);
	not_between_constraints = !(0 < curr_arg && curr_arg <= 250);
	if (curr_arg_is_num_philos && not_between_constraints)
	{
		report_and_set_error(dinner, ERR_NUM_PHILOS, MSG_NUM_PHILOS);
		return (true);
	}
	else
		return (false);
}
