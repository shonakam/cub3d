/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:15:24 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 11:19:45 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_collision(double x, double y, char **map)
{
	double	angle;

	angle = 0;
	while (angle < 2 * M_PI)
	{
		double check_x = x + cos(angle) * RADIUS;
		double check_y = y + sin(angle) * RADIUS;
		if (map[(int)check_y][(int)check_x] == '1')
			return 1;
		angle += M_PI / 4;
	}
	return (0);
}
