/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 04:06:27 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 13:56:56 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_internal.h"

static int	set_start(const double whd)
{
	int	result;

	result = (int)(WINDOW_HEIGHT / whd) / 2 + WINDOW_HEIGHT / 2;
	return (-result);
}

static int	set_end(const double whd)
{
	int	result;

	result = (int)(WINDOW_HEIGHT / whd) / 2 + WINDOW_HEIGHT / 2;
	return (result);
}	

void	ft_render(t_cub3d *cub)
{
	int		x;
	t_ray	ray;
	t_image	img;
	t_vec_i	range;

	img.ptr = mlx_new_image(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.data = mlx_get_data_addr(
			img.ptr, &img.bpp, &img.line_length, &img.endian);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		init_ray(cub, &ray, x);
		perform_dda(cub, &ray);
		draw_wall(&img, &ray, x, cub->textures);
		range.x = set_start(ray.wall_hit_distance);
		range.y = set_end(ray.wall_hit_distance);
		draw_ceiling(&img, cub, x, range.x);
		draw_floor(&img, cub, x, range.y);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, img.ptr, 0, 0);
	mlx_destroy_image(cub->mlx, img.ptr);
}
