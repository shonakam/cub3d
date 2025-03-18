/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:28:51 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 01:57:09 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_player(t_player *p, char **map, double delta_time, t_vec_d move)
{
	double	move_speed;
	t_vec_d	new;

	if (delta_time > 0.1)
		delta_time = 0.1;
	move_speed = BASE_MOVE_SPEED * delta_time;
	new.x = p->position.x + move.x * move_speed;
	new.y = p->position.y + move.y * move_speed;
	if (map[(int)new.y][(int)new.x] != '1')
	{
		p->position.x = new.x;
		p->position.y = new.y;
	}
}

void	move_forward(t_cub3d *cub)
{
	t_vec_d	move_vec;

	move_vec.x = cub->player.direction.x;
	move_vec.y = cub->player.direction.y;
	move_player(&cub->player, cub->map.col, get_delta_time(), move_vec);
}

void	move_backward(t_cub3d *cub)
{
	t_vec_d	move_vec;

	move_vec.x = -cub->player.direction.x;
	move_vec.y = -cub->player.direction.y;
	move_player(&cub->player, cub->map.col, get_delta_time(), move_vec);
}

void	move_left(t_cub3d *cub)
{
	t_vec_d	move_vec;

	move_vec.x = -cub->player.plane.x;
	move_vec.y = -cub->player.plane.y;
	move_player(&cub->player, cub->map.col, get_delta_time(), move_vec);
}

void	move_right(t_cub3d *cub)
{
	t_vec_d	move_vec;

	move_vec.x = cub->player.plane.x;
	move_vec.y = cub->player.plane.y;
	move_player(&cub->player, cub->map.col, get_delta_time(), move_vec);
}


