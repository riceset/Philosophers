/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_only_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:39:57 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:47:59 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	not_only_digits(char *str, t_dinner *dinner)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_digit(str[i]))
		{
			report_and_set_error(dinner, ERR_NOT_ONLY_DIGITS,
				MSG_NOT_ONLY_DIGITS);
			return (true);
		}
		i++;
	}
	return (false);
}
