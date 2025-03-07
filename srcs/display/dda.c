/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:56:08 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/07 15:38:30 by shonakam         ###   ########.fr       */
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

static void	prevent_zero_division(double *value)
{
	if (fabs(*value) < 1e-6)
	{
		if (*value < 0)
			*value = -1e-6;
		else
			*value = 1e-6;
	}
}

static void	calculate_wall_distance(t_player *p, t_ray *ray)
{
	double	numerator;
	double	denominator;

	prevent_zero_division(&ray->direction.x);
	prevent_zero_division(&ray->direction.y);
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
