/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_support.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:25:52 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 14:04:25 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../display_internal.h"

int	calculate_line_height(t_ray *ray)
{
	return ((int)(WINDOW_HEIGHT / fmax(ray->wall_hit_distance, 0.1)));
}

int	calculate_draw_start(int line_height)
{
	return (-line_height / 2 + WINDOW_HEIGHT / 2);
}

int	calculate_draw_end(int line_height)
{
	return (line_height / 2 + WINDOW_HEIGHT / 2);
}

double	calculate_wall_hit_x(t_ray *ray)
{
	double	wall_hit_x;

	if (ray->side == 0)
		wall_hit_x = ray->pos.y + ray->wall_hit_distance * ray->direction.y;
	else
		wall_hit_x = ray->pos.x + ray->wall_hit_distance * ray->direction.x;
	wall_hit_x -= floor(wall_hit_x);
	return (wall_hit_x);
}
