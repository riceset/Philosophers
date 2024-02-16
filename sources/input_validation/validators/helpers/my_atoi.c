/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:40:14 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:40:15 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_atoi(const char *str)
{
	long long	res;

	res = 0;
	while (*str != '\0')
	{
		res = res * 10 + (*str - '0');
		if (res > INT_MAX)
			return (ERR_ATOI);
		str++;
	}
	return ((int)(res));
}
