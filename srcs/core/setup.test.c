/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:32:29 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 12:19:47 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

void	set_texture(t_cub3d *cub)
{
	char *n = "./assets/textures/north_texture.xpm";
	char *s = "./assets/textures/south_texture.xpm";
	char *w = "./assets/textures/west_texture.xpm";
	char *e = "./assets/textures/east_texture.xpm";

	// テクスチャ画像の読み込み
	cub->textures[0].image.ptr = mlx_xpm_file_to_image(cub->mlx, n, &cub->textures[0].width, &cub->textures[0].height);
	cub->textures[1].image.ptr = mlx_xpm_file_to_image(cub->mlx, s, &cub->textures[1].width, &cub->textures[1].height);
	cub->textures[2].image.ptr = mlx_xpm_file_to_image(cub->mlx, w, &cub->textures[2].width, &cub->textures[2].height);
	cub->textures[3].image.ptr = mlx_xpm_file_to_image(cub->mlx, e, &cub->textures[3].width, &cub->textures[3].height);

	// 画像データの取得
	int bpp, line_length, endian;
	for (int i = 0; i < 4; i++) {
		cub->textures[i].image.data = mlx_get_data_addr(cub->textures[i].image.ptr, &bpp, &line_length, &endian);
		cub->textures[i].image.bpp = bpp;
		cub->textures[i].image.line_length = line_length;
		cub->textures[i].image.endian = endian;
	}
}


void set_map(t_cub3d *cub)
{
	cub->map.width = 6;
	cub->map.height = 5;
	cub->map.col = malloc(sizeof(char *) * (cub->map.height + 1));
	cub->map.col[0] = ft_strdup("111111");
	cub->map.col[1] = ft_strdup("100101");
	cub->map.col[2] = ft_strdup("101001");
	cub->map.col[3] = ft_strdup("1100N1");
	cub->map.col[4] = ft_strdup("111111");
	cub->map.col[5] = NULL;

	for (int y = 0; y < cub->map.height; y++)
	{
		for (int x = 0; x < cub->map.width; x++)
		{
			if (cub->map.col[y][x] == 'N')  // プレイヤーの初期位置を見つける
			{
				cub->player.position.x = x + 0.5;  // プレイヤーを中央に補正
				cub->player.position.y = y + 0.5;
				cub->map.col[y][x] = '0';  // 'N' を '0' に置き換え
			}
		}
	}
}

void	set_fov(t_player *player, double fov)
{
	double	plane_length;
	double	fov_radians = (fov * M_PI) / 180.0;

	plane_length = tan(fov_radians / 2);
	player->plane.x = -player->direction.y * plane_length;
	player->plane.y = player->direction.x * plane_length;
}

void	set_player(t_player *player)
{
	player->direction.x = 0;
	player->direction.y = -1;
	set_fov(player, 60);
}

void	setup_cub(t_cub3d *cub)
{
	cub->floor_color = ft_rgbtoi(173, 216, 230);
	cub->ceiling_color = ft_rgbtoi(0, 0, 0);
	set_map(cub);
	set_texture(cub);
	set_player(&cub->player);
}
