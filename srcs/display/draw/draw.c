/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:50:16 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 21:36:10 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../display_internal.h"

void	put_pixel_to_image(t_image *img, int x, int y, int color)
{
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	*(int *)(img->data + (y * img->line_length + x * (img->bpp / 8))) = color;
}

static double	calculate_wall_hit_x(t_ray *ray)
{
	double	wall_hit_x;

	if (ray->side == 0)
		wall_hit_x = ray->pos.y + ray->wall_hit_distance * ray->direction.y;
	else
		wall_hit_x = ray->pos.x + ray->wall_hit_distance * ray->direction.x;
	wall_hit_x -= floor(wall_hit_x);
	return (wall_hit_x);
}

void	draw_wall(t_image *img, t_ray *ray, int x, t_texture textures[4])
{
	t_wall_render	wall;
	int				y;

	wall.line_height
		= (int)(WINDOW_HEIGHT / fmax(ray->wall_hit_distance, 0.1));
	wall.draw_start = -wall.line_height / 2 + WINDOW_HEIGHT / 2;
	wall.draw_end = wall.line_height / 2 + WINDOW_HEIGHT / 2;
	wall.wall_texture = set_wall_texture(ray, textures);
	wall.tex.x = calculate_texture_x(ray, &wall);
	wall.wall_hit_x = calculate_wall_hit_x(ray);
	wall.tex.x = (int)(wall.wall_hit_x * wall.wall_texture->width);
	wall.tex_height = wall.wall_texture->height;
	y = wall.draw_start;
	while (y < wall.draw_end)
	{
		wall.tex.y = ((y - wall.draw_start) * wall.wall_texture->height)
			/ wall.line_height;
		if (wall.tex.y < 0 || wall.tex.y >= wall.tex_height)
			continue ;
		wall.color = get_texture_pixel(wall.wall_texture, wall.tex, ray);
		put_pixel_to_image(img, x, y, wall.color);
		y++;
	}
}

void	draw_ceiling(t_image *img, t_cub3d *cub, int x, int start)
{
	int	y;

	y = 0;
	while (y < start)
	{
		put_pixel_to_image(img, x, y, cub->ceiling_color);
		y++;
	}
}

void	draw_floor(t_image *img, t_cub3d *cub, int x, int end)
{
	while (end < WINDOW_HEIGHT)
	{
		put_pixel_to_image(img, x, end, cub->floor_color);
		end++;
	}
}
