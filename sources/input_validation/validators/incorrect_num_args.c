/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incorrect_num_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:39:54 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:50:45 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	incorrect_num_of_args(int argc, t_dinner *dinner)
{
	bool	time_to_die_provided;
	bool	time_to_die_not_provided;

	time_to_die_provided = (argc < 5);
	time_to_die_not_provided = (argc > 6);
	if (time_to_die_provided || time_to_die_not_provided)
	{
		report_and_set_error(dinner, ERR_NUM_ARGS, MSG_NUM_ARGS);
		return (true);
	}
	else
		return (false);
}
