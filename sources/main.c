/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:37:17 by tkomeno           #+#    #+#             */
/*   Updated: 2024/02/16 10:37:28 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	if (can_prepare_dinner(&dinner, argc, argv))
	{
		start_dinner(&dinner);
		end_dinner(&dinner);
	}
	return (dinner.exit_status);
}
