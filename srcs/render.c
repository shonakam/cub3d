/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:03:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/06 02:06:16 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void   set_cub(t_cub3d *cub)
{
    cub->mlx = mlx_init();
    cub->win = mlx_new_window(cub->mlx, cub->config.res.x, cub->config.res.y, "cub3d");
    set_txt(cub);
    set_map(cub);
    set_rendered(cub);
    set_player(cub);
    set_textures(cub);
    cub->floor_color = get_floor_color(cub->txt);
    cub->ceiling_color = get_ceiling_color(cub->txt);
}

void   set_map(t_cub3d *cub)
{
    cub->map->width = map_width(cub->txt);
    cub->map->height = map_height(cub->txt);
    cub->map->map = map_setting(cub->txt);
}

void    set_rendered(t_cub3d *cub)
{
    cub->rendered.img = mlx_new_image(cub->mlx, cub->config.res.x, cub->config.res.y);
    cub->rendered.addr = mlx_get_data_addr(cub->rendered.img, &cub->rendered.bpp, &cub->rendered.line_length, &cub->rendered.endian);
    cub->rendered.bpp = 24;
    
}

void    set_player(t_cub3d *cub)
{
    int	x;
	int	y;

    y = 0;
    while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'N')
			{
				cub->p_x = x;
				cub->p_y = y;
                cub->player.direction.x = -1;
                cub->player.direction.y = 0;
			}
			else if (cub->map[y][x] == 'E')
			{
				cub->p_x = x;
				cub->p_y = y;
                cub->player.direction.x = 0;
                cub->player.direction.y = 1;
			}
			else if (cub->map[y][x] == 'W')
			{
				cub->p_x = x;
				cub->p_y = y;
                cub->player.direction.x = 0;
                cub->player.direction.y = -1;
			}
			else if (cub->map[y][x] == 'S')
			{
				cub->p_x = x;
				cub->p_y = y;
                cub->player.direction.x = 1;
                cub->player.direction.y = 0;
			}
			x++;
		}
		y++;
	}
    cub->player.camera_plane.x = 0;
    cub->player.camera_plane.y = 0;
    cub->player.movement_speed = PLAYER_SPEED;
    cub->player.rotation_speed = ROTATION_SPEED;
}

void    set_textures(t_cub3d *cub)
{
    int i;

    i = 0;
    while (i < 4)
    {
        sett_textures_utils(cub->textures[i]);
        i++;
    }
}

void    set_textures_utils(t_texture *textures)
{
    cub->textures->img = mlx_xpm_file_to_image(cub->mlx, cub->config.textures[NORTH], &cub->textures[NORTH].width, &cub->textures[NORTH].height);
    cub->textures->data = (int *)mlx_get_data_addr(cub->textures[NORTH].img, &cub->textures[NORTH].bpp, &cub->textures[NORTH].line_length, &cub->textures[NORTH].endian);
}

char **map_setting(t_cub3d *cub, char **text)
{
    size_t i;
    size_t j;
    size_t k;
    char **map;

    i = 0;
    k = 0;
    map = malloc(sizeof(char *) * (map_height(text) + 1));
    if (!map)
        return (NULL);
    while (text[i])
    {
        j = 0;
        while (text[i][j] == ' ')
            j++;
        if (text[i][j] == '1')
        {
            map[k] = malloc(sizeof(char) * (map_width(text) + 1));
            if (!map[k])
                return (free(map), NULL);
            while (text[i][j])
            {
                map[k][j] = text[i][j];
                j++;
            }
            while (j < map_width(text))
            {
                map[k][j] = ' ';
                j++;
            }
            map[k][j] = '\0';
            k++;
        }
        i++;
    }
    map[k] = NULL;
    return (map);
}