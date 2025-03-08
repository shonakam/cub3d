/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:05:28 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 11:07:52 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

double	get_delta_time()
{
	static struct timeval	last_time = {0};
	struct timeval			current_time;
	double					delta_time;

	gettimeofday(&current_time, NULL);
	if (last_time.tv_sec == 0 && last_time.tv_usec == 0)
	{
		last_time = current_time;
		return (0.0);
	}
	delta_time = (current_time.tv_sec - last_time.tv_sec) +
				(current_time.tv_usec - last_time.tv_usec) / 1000000.0;
	last_time = current_time;
	return (delta_time);
}
