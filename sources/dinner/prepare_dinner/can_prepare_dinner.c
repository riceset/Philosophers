/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_prepare_dinner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:37:57 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:37:59 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	can_prepare_dinner(t_dinner *dinner, int argc, char **argv)
{
	initialize_exit_status(dinner);
	if (correct_input(dinner, argc, argv))
	{
		set_dinner_rules(dinner, argc, argv);
		if (can_initialize_forks(dinner))
		{
			initialize_philosophers(dinner);
			if (can_initialize_stop_mutex(dinner))
				if (can_initialize_print_mutex(dinner))
					return (true);
		}
	}
	return (false);
}
