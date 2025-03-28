/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:15:24 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 14:16:24 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_collision(double x, double y, char **map)
{
	double	angle;
	t_vec_d	check;

	angle = 0;
	while (angle < (2 * get_pi()))
	{
		check.x = x + cos(angle) * RADIUS;
		check.y = y + sin(angle) * RADIUS;
		if (map[(int)check.y][(int)check.x] == '1')
			return (1);
		angle += get_pi() / 4;
	}
	return (0);
}
