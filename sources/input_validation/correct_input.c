/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:39:42 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 14:57:29 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	correct_input(t_dinner *dinner, int argc, char **argv)
{
	int	i;
	int	curr_arg;

	if (incorrect_num_of_args(argc, dinner))
		return (false);
	i = 1;
	while (i < argc)
	{
		if (not_only_digits(argv[i], dinner))
			return (false);
		if (!can_convert_str_to_int(dinner, argv[i], &curr_arg))
			return (false);
		if (wrong_num(i, curr_arg, dinner))
			return (false);
		i++;
	}
	return (true);
}
