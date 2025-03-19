/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:58:10 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 13:59:05 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_internal.h"

static void	init_ray_base(t_cub3d *cub, t_ray *ray, int x)
{
	ray->screen_relative_x = (2.0 * x / (double)WINDOW_WIDTH) - 1.0;
	ray->map.x = (int)cub->player.position.x;
	ray->map.y = (int)cub->player.position.y;
	ray->pos = cub->player.position;
	ray->direction.x = cub->player.direction.x + cub->player.plane.x
		* ray->screen_relative_x;
	ray->direction.y = cub->player.direction.y + cub->player.plane.y
		* ray->screen_relative_x;
	if (ray->direction.x == 0)
		ray->delta_distance.x = 1e30;
	else
		ray->delta_distance.x = fmax(fabs(1 / ray->direction.x), 1e-6);
	if (ray->direction.y == 0)
		ray->delta_distance.y = 1e30;
	else
		ray->delta_distance.y = fmax(fabs(1 / ray->direction.y), 1e-6);
	ray->hit = 0;
}

static void	calculate_ray_steps(t_cub3d *cub, t_ray *ray)
{
	if (ray->direction.x < 0)
	{
		ray->step.x = -1;
		ray->side_distance.x = (cub->player.position.x - ray->map.x)
			* ray->delta_distance.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_distance.x = (ray->map.x + 1.0 - cub->player.position.x)
			* ray->delta_distance.x;
	}
	if (ray->direction.y < 0)
	{
		ray->step.y = -1;
		ray->side_distance.y = (cub->player.position.y - ray->map.y)
			* ray->delta_distance.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_distance.y = (ray->map.y + 1.0 - cub->player.position.y)
			* ray->delta_distance.y;
	}
}

void	init_ray(t_cub3d *cub, t_ray *ray, int x)
{
	init_ray_base(cub, ray, x);
	calculate_ray_steps(cub, ray);
}
