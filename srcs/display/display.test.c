/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:20:48 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/06 04:36:10 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	free_cub(t_cub3d *cub)
{
	size_t i = 0;

	while (i < cub->map.height)
		free(cub->map.col[i++]);
	free(cub->map.col);
	free(cub);
}

static void	set_texture(t_cub3d *cub)
{
	char *n = "./assets/textures/north_texture.xpm";
	char *s = "./assets/textures/south_texture.xpm";
	char *w = "./assets/textures/west_texture.xpm";
	char *e = "./assets/textures/east_texture.xpm";

	cub->textures[0].img = mlx_xpm_file_to_image(cub->mlx, n, &cub->textures[0].width, &cub->textures[0].height);
	cub->textures[1].img = mlx_xpm_file_to_image(cub->mlx, s, &cub->textures[1].width, &cub->textures[1].height);
	cub->textures[2].img = mlx_xpm_file_to_image(cub->mlx, w, &cub->textures[2].width, &cub->textures[2].height);
	cub->textures[3].img = mlx_xpm_file_to_image(cub->mlx, e, &cub->textures[3].width, &cub->textures[3].height);
	cub->textures[0].data = (int *)mlx_get_data_addr(cub->textures[0].img, &(int){0}, &(int){0}, &(int){0});
	cub->textures[1].data = (int *)mlx_get_data_addr(cub->textures[1].img, &(int){0}, &(int){0}, &(int){0});
	cub->textures[2].data = (int *)mlx_get_data_addr(cub->textures[2].img, &(int){0}, &(int){0}, &(int){0});
	cub->textures[3].data = (int *)mlx_get_data_addr(cub->textures[3].img, &(int){0}, &(int){0}, &(int){0});
}

static void set_map(t_cub3d *cub)
{
	cub->map.width = 6;
	cub->map.height = 6;
	cub->map.col = malloc(sizeof(char *) * 6);
	cub->map.col[0] = ft_strdup("111111");
	cub->map.col[1] = ft_strdup("100101");
	cub->map.col[2] = ft_strdup("101001");
	cub->map.col[3] = ft_strdup("1100N1");
	cub->map.col[4] = ft_strdup("111111");
	cub->map.col[5] = NULL;
}

static void	set_player(t_player *player)
{
	player->position.x = 0.5;
	player->position.y = 0.5;
	player->direction.x = 0;
	player->direction.y = -1;
	
}

static void setup(t_cub3d *cub)
{
	cub->mlx = mlx_init();
	cub->floor_color = ft_rgbtoi(220, 100, 0);
	cub->ceiling_color = ft_rgbtoi(225, 30, 0);
	init_render(cub);
	set_map(cub);
	set_texture(cub);
	set_player(&cub->player);
}

int main(void)
{
	t_cub3d *cub = initialize_cub();

	setup(cub);
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	ft_render(cub);
	mlx_loop(cub->mlx);
	return (free_cub(cub), 0);
}
