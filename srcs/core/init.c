/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:53:18 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/06 03:57:11 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

// static void	init_textures_map(t_cub3d *cub)
// {
// 	int		i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		cub->textures[i].img = NULL;
// 		i++;
// 	}
// 	cub->map = NULL;
// }

// static void	*init_mlx(t_cub3d *cub)
// {
// 	cub->mlx = mlx_init();
// 	if (!cub->mlx)
// 		return (perror("Error: Failed to initialize MiniLibX"), NULL);
// 	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
// 	if (!cub->win)
// 		return (perror("Error: Failed to create window"), NULL);
// 	// cub->rendered.img = NULL;
// 	return (cub->mlx);
// }

// static void init_position_direction(t_cub3d *cub)
// {
// 	cub->player.position.x = 0;
// 	cub->player.position.y = 0;
// 	cub->player.direction.x = -1;
// 	cub->player.direction.y = 0;
// 	cub->player.camera_plane.x = 0;
// 	cub->player.camera_plane.y = 0.66;
// 	cub->player.movement_speed = PLAYER_SPEED;
// 	cub->player.rotation_speed = ROTATION_SPEED;
// }

// t_cub3d	*initialize_cub(void)
// {
// 	t_cub3d	*cub;

// 	cub = malloc(sizeof(t_cub3d));
// 	if (!cub)
// 		return (NULL);
// 	if (!init_mlx(cub))
// 		return (free(cub), NULL);
// 	// init_position_direction(cub);
// 	init_textures_map(cub);
// 	return (cub);
// }

t_cub3d	*initialize_cub(void)
{
	t_cub3d	*cub;
	int		i;

	cub = malloc(sizeof(t_cub3d));
	if (!cub)
	{
		perror("Error: Failed to allocate memory for cub3d\n");
		return (NULL);
	}
	cub->mlx = NULL;
	cub->win = NULL;
	cub->floor_color = -1;
	cub->ceiling_color = -1;
	i = 0;
	while (i < 4)
		cub->textures[i++].img = NULL;
	return (cub);
}
