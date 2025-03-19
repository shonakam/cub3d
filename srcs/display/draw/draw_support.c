/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:09:41 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 11:25:58 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../display_internal.h"

int	get_texture_pixel(t_texture *texture, t_vec_i tex)
{
	char	*pixel;
	int		color;

	if (tex.x < 0 || tex.x >= texture->width || tex.y < 0 || tex.y >= texture->height)
		return (0xFF00FF);
	pixel = texture->image.data
		+ (tex.y * texture->image.line_length) + (tex.x * (texture->image.bpp / 8));
	if (texture->image.endian == 0)
		color = *(int *)pixel;
	else 
		color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3];
	return (color);
}

t_texture	*set_wall_texture(t_ray *ray, t_texture textures[4])
{
	if (ray->side == 0)
	{
		if (ray->step.x > 0)
			return (&textures[3]);
		return (&textures[2]);
	}
	else
	{
		if (ray->step.y > 0)
			return (&textures[1]);
		return (&textures[0]);
	}
}

void	clamp_wall_draw_range(t_wall_render *wall)
{
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	if (wall->draw_end >= WINDOW_HEIGHT)
		wall->draw_end = WINDOW_HEIGHT - 1;
}

int	calculate_texture_x(t_ray *ray, t_wall_render *wall)
{
	double	hit_position;
	int		texture_x;
	int		texture_width;

	texture_width = wall->wall_texture->width;
	if (ray->side == 0)
		hit_position = ray->map.y + ray->wall_hit_distance * ray->direction.y;
	else
		hit_position = ray->map.x + ray->wall_hit_distance * ray->direction.x;
	hit_position -= floor(hit_position);
	if ((ray->side == 0 && ray->direction.x > 0) || (ray->side == 1 && ray->direction.y < 0))
		hit_position = 1.0 - hit_position;
	texture_x = (int)(hit_position * texture_width);
	if (texture_x < 0)
		texture_x = 0;
	if (texture_x >= texture_width)
		texture_x = texture_width - 1;
	return (texture_x);
}
