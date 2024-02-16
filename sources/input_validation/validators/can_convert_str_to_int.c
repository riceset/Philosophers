/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_convert_str_to_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:39:51 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:39:52 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	can_convert_str_to_int(t_dinner *dinner, const char *str, int *res)
{
	long long	n;

	n = 0;
	while (*str != '\0')
	{
		n = n * 10 + (*str - '0');
		if (n > INT_MAX)
		{
			report_and_set_error(dinner, ERR_ATOI, MSG_ATOI);
			return (false);
		}
		str++;
	}
	*res = n;
	return (true);
}
