/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:56:33 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 01:57:06 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_player *player, double delta_time, int direction)
{
	double	angle;
	double	old_dir_x;
	double	old_plane_x;
	double	rad;

	if (delta_time > 0.1)
		delta_time = 0.1;
	angle = BASE_ROT_SPEED * delta_time * direction;
	old_dir_x = player->direction.x;
	old_plane_x = player->plane.x;
	rad = angle * (M_PI / 180.0);
	player->direction.x 
		= player->direction.x * cos(rad) - player->direction.y * sin(rad);
	player->direction.y 
		= old_dir_x * sin(rad) + player->direction.y * cos(rad);
	player->plane.x = player->plane.x * cos(rad) - player->plane.y * sin(rad);
	player->plane.y = old_plane_x * sin(rad) + player->plane.y * cos(rad);
}

void	rotate_right(t_cub3d *cub)
{
	rotate_player(&cub->player, get_delta_time(), 1);
}

void	rotate_left(t_cub3d *cub)
{
	rotate_player(&cub->player, get_delta_time(), -1);
}
