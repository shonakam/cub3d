/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:20:48 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 08:32:56 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <time.h> 

void	rotate_player(t_player *player, double angle)
{
	double old_dir_x = player->direction.x;
	double old_plane_x = player->plane.x;

	// 角度をラジアンに変換
	double rad = angle * (M_PI / 180.0);

	// **方向ベクトルの回転**
	player->direction.x = player->direction.x * cos(rad) - player->direction.y * sin(rad);
	player->direction.y = old_dir_x * sin(rad) + player->direction.y * cos(rad);

	// **カメラ平面の回転**
	player->plane.x = player->plane.x * cos(rad) - player->plane.y * sin(rad);
	player->plane.y = old_plane_x * sin(rad) + player->plane.y * cos(rad);
}

void	update_rotation(t_cub3d *cub)
{
	double current_time = (double)clock() / CLOCKS_PER_SEC;
	if (current_time - cub->last_rotation_time >= 0.5)
	{
		rotate_player(&cub->player, 10.0); // **10度ずつ右回転**
		cub->last_rotation_time = current_time; // **回転した時間を更新**
	}
}

int game_loop(t_cub3d *cub)
{
	update_rotation(cub); // **2秒ごとに回転**
	ft_render(cub);       // **画面を更新**
	return (0);
}

int main(void)
{
	t_cub3d *cub = initialize_cub();

	cub->last_rotation_time = (double)clock() / CLOCKS_PER_SEC;

	setup(cub);
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");

	// ft_render(cub);
	mlx_loop_hook(cub->mlx, game_loop, cub);
	mlx_loop(cub->mlx);
	return (free_cub(cub), 0);
}
