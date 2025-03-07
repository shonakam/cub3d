/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:56:08 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/07 14:30:27 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_internal.h"

static void	step_dda(t_cub3d *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_distance.x < ray->side_distance.y)
		{
			ray->side_distance.x += ray->delta_distance.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_distance.y += ray->delta_distance.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (cub->map.col[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

static void	calculate_wall_distance(t_player *p, t_ray *ray)
{
	double	numerator;
	double	denominator;

	if (fabs(ray->direction.x) < 1e-6)
		ray->direction.x = (ray->direction.x < 0) ? -1e-6 : 1e-6;
	if (fabs(ray->direction.y) < 1e-6)
		ray->direction.y = (ray->direction.y < 0) ? -1e-6 : 1e-6;
	if (ray->side == 0)
	{
		numerator = ray->map.x - p->position.x + (1 - ray->step.x) / 2;
		denominator = ray->direction.x;
	}
	else
	{
		numerator = ray->map.y - p->position.y + (1 - ray->step.y) / 2;
		denominator = ray->direction.y;
	}
	ray->wall_hit_distance = numerator / denominator;
}


void	perform_dda(t_cub3d *cub, t_ray *ray)
{
	step_dda(cub, ray);
	calculate_wall_distance(&cub->player, ray);
}
