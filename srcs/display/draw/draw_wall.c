// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw_wall.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/08 14:01:51 by shonakam          #+#    #+#             */
// /*   Updated: 2025/03/08 14:25:16 by shonakam         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../display_internal.h"

// double	get_wall_hit_x(t_ray *ray)
// {
// 	double	wall_hit_x;

// 	if (ray->side == 0)
// 	{
// 		wall_hit_x 
// 			= ray->pos.y + ray->wall_hit_distance * ray->direction.y;
// 	}
// 	else
// 	{
// 		wall_hit_x
// 			= ray->pos.x + ray->wall_hit_distance * ray->direction.x;
// 	}
// 	return (wall_hit_x - floor(wall_hit_x));
// }

// void	calculate_wall_height(t_wall_render *wall, t_ray *ray)
// {
// 	wall->line_height = (int)(WINDOW_HEIGHT / fmax(ray->wall_hit_distance, 0.1));
// 	wall->draw_start = fmax(0, -wall->line_height / 2 + WINDOW_HEIGHT / 2);
// 	wall->draw_end = fmin(WINDOW_HEIGHT - 1, wall->line_height / 2 + WINDOW_HEIGHT / 2);
// }

// int	calculate_tex_x(double wall_hit_x, t_texture *texture, t_ray *ray)
// {
// 	int tex_x;

// 	tex_x = (int)(wall_hit_x * texture->width);
// 	if (tex_x < 0)
// 		tex_x = 0;
// 	else if (tex_x >= texture->width)
// 		tex_x = texture->width - 1;
// 	if ((ray->side == 0 && ray->direction.x > 0)
// 		|| (ray->side == 1 && ray->direction.y < 0))
// 		tex_x = texture->width - tex_x - 1;
// 	return (tex_x);
// }

// void	draw_wall_section(t_image *img, t_wall_render *wall, int x)
// {
// 	int			color;
// 	int			y;
// 	t_vec_i		tex;

// 	y = wall->draw_start;
// 	tex.x = wall->tex.x;
// 	while (y < wall->draw_end)
// 	{
// 		tex.y = ((y - wall->draw_start) * wall->wall_texture->height) / wall->line_height;
// 		if (tex.y >= 0 && tex.y < wall->wall_texture->height)
// 		{
// 			color = get_texture_pixel(wall->wall_texture, tex);
// 			put_pixel_to_image(img, x, y, color);
// 		}
// 		y++; 
// 	}
// }

// void	draw_wall(t_image *img, t_ray *ray, int x, t_texture textures[4])
// {
// 	t_wall_render	wall;

// 	calculate_wall_height(&wall, ray);
// 	wall.wall_texture = set_wall_texture(ray, textures);
// 	wall.wall_hit_x = get_wall_hit_x(ray);
// 	wall.tex.x = calculate_tex_x(wall.wall_hit_x, wall.wall_texture, ray);
// 	draw_wall_section(img, &wall, x);
// }