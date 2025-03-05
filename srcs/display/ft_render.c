/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 04:06:27 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/06 04:35:04 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	draw_ceiling(t_cub3d *cub)
{
	int	*pixels;
	int	x;
	int	y;

	pixels = (int *)cub->rendered.addr;
	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pixels[y * WINDOW_WIDTH + x] = cub->ceiling_color;
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_cub3d *cub)
{
	int	*pixels;
	int	x;
	int	y;

	pixels = (int *)cub->rendered.addr;
	y = WINDOW_HEIGHT / 2;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			pixels[y * WINDOW_WIDTH + x] = cub->floor_color;
			x++;
		}
		y++;
	}
}

void	init_render(t_cub3d *cub)
{
	if (!cub || !cub->mlx)
		return ;
	cub->rendered.img = mlx_new_image(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!cub->rendered.img)
	{
		ft_putendl_fd("Error: Failed to create image", 2);
		return ;
	}
	cub->rendered.addr = mlx_get_data_addr(
		cub->rendered.img, &(int){0}, &(int){0}, &(int){0});
	if (!cub->rendered.addr)
		ft_putendl_fd("Error: Failed to get image address", 2);
}

void	ft_render(t_cub3d *cub)
{
	draw_ceiling(cub);
	draw_floor(cub);
	ft_raycaster(cub);
	mlx_put_image_to_window(
		cub->mlx,
		cub->win,
		cub->rendered.img,
		0,
		0
	);
}
