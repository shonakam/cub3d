/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:28:51 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 13:10:17 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

// 衝突判定を行い、プレイヤーを移動させる
static void	move_player(t_player *p, char **map, double delta_time, t_vec_d direction)
{
	double	move_speed;
	t_vec_d	new;

	if (delta_time > 0.1)
		delta_time = 0.1;
	move_speed = BASE_MOVE_SPEED * delta_time;
	if (direction.x != direction.y)
	{
		new.x = p->position.x + direction.x * p->plane.x * move_speed;
		new.y = p->position.y + direction.y * p->plane.y * move_speed;
	}
	else
	{
		new.x = p->position.x + direction.x * p->direction.x * move_speed;
		new.y = p->position.y + direction.y * p->direction.y * move_speed;
	}
	if (map[(int)new.y][(int)new.x] != '1')
	{
		p->position.x = new.x;
		p->position.y = new.y;
	}
}

void	move_forward(t_cub3d *cub)
{
	t_vec_d	direction;

	direction = (t_vec_d){1, 1};
	move_player(&cub->player, cub->map.col, get_delta_time(), direction);
}

void	move_backward(t_cub3d *cub)
{
	t_vec_d	direction;

	direction = (t_vec_d){-1, -1};
	move_player(&cub->player, cub->map.col, get_delta_time(), direction);
}

void	move_left(t_cub3d *cub)
{
	t_vec_d	direction;

	direction = (t_vec_d){-1, 1};
	move_player(&cub->player, cub->map.col, get_delta_time(), direction);
}

void	move_right(t_cub3d *cub)
{
	t_vec_d	direction;

	direction = (t_vec_d){1, -1};
	move_player(&cub->player, cub->map.col, get_delta_time(), direction);
}

