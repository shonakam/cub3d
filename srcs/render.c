#include "../includes/cub3d.h"

void   set_game(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->config.res.x, game->config.res.y, "cub3d");
    set_txt(game);
    set_map(game);
    set_rendered(game);
    set_player(game);
    set_textures(game);
    game->floor_color = get_floor_color(game->txt);
    game->ceiling_color = get_ceiling_color(game->txt);
}

void   set_map(t_game *game)
{
    game->map->width = map_width(game->txt);
    game->map->height = map_height(game->txt);
    game->map->map = map_setting(game->txt);
}

void    set_rendered(t_game *game)
{
    game->rendered.img = mlx_new_image(game->mlx, game->config.res.x, game->config.res.y);
    game->rendered.addr = mlx_get_data_addr(game->rendered.img, &game->rendered.bpp, &game->rendered.line_length, &game->rendered.endian);
    game->rendered.bpp = 24;
    
}

void    set_player(t_game *game)
{
    int	x;
	int	y;

    y = 0;
    while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N')
			{
				game->p_x = x;
				game->p_y = y;
                game->player.direction.x = -1;
                game->player.direction.y = 0;
			}
			else if (game->map[y][x] == 'E')
			{
				game->p_x = x;
				game->p_y = y;
                game->player.direction.x = 0;
                game->player.direction.y = 1;
			}
			else if (game->map[y][x] == 'W')
			{
				game->p_x = x;
				game->p_y = y;
                game->player.direction.x = 0;
                game->player.direction.y = -1;
			}
			else if (game->map[y][x] == 'S')
			{
				game->p_x = x;
				game->p_y = y;
                game->player.direction.x = 1;
                game->player.direction.y = 0;
			}
			x++;
		}
		y++;
	}
    game->player.camera_plane.x = 0;
    game->player.camera_plane.y = 0;
    game->player.movement_speed = PLAYER_SPEED;
    game->player.rotation_speed = ROTATION_SPEED;
}

void    set_textures(t_game *game)
{
    int i;

    i = 0;
    while (i < 4)
    {
        sett_textures_utils(game->textures[i]);
        i++;
    }
}

void    set_textures_utils(t_texture *textures)
{
    game->textures->img = mlx_xpm_file_to_image(game->mlx, game->config.textures[NORTH], &game->textures[NORTH].width, &game->textures[NORTH].height);
    game->textures->data = (int *)mlx_get_data_addr(game->textures[NORTH].img, &game->textures[NORTH].bpp, &game->textures[NORTH].line_length, &game->textures[NORTH].endian);
}

char **map_setting(t_game *game, char **text)
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