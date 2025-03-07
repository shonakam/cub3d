#include "../includes/cub3d.h"

void	set_game(t_game *game, const char *file_path)
{
	set_txt(game, file_path);
	if (!is_con_txt(game->txt))
		return (error_print(INVALID_TXT), exit(1));
	set_map(game);
	if (!is_con_map(game->map->map))
		return (error_print(INVALID_MAP), exit(1));
	// game->mlx = mlx_init();
	// game->win = mlx_new_window(game->mlx, game->config.res.x, game->config.res.y, "cub3d");
	// set_rendered(game);
	set_player(game);
	set_textures(game);
	set_ceil_floor(game);
}

void	set_txt(t_game *game, const char *file_path)
{
	int		file;
	char	*line;
	size_t	i;
	size_t	len;

	i = 0;
	file = open(file_path, O_RDONLY);
	if (file == -1)
		return (error_print(OPEN_ERROR), exit(1));
	game->map = malloc(sizeof(char *) * game->map->height + 1);
	if (!game->map)
		return (error_print(ALLOCATE_ERROR), close(file), exit(1));
	while ((line = get_next_line(file)) != NULL)
	{
		game->txt[i++] = line;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
	}
	game->txt[i] = NULL;
	close(file);
}

void	set_map(t_game *game)
{
	game->map->width = map_width(game->txt);
	game->map->height = map_height(game->txt);
	if (game->map->width == 0 || game->map->height == 0)
		return (error_print(INVALID_MAP_SIZE), free_game(game));
	game->map->map = map_setting(game, game->txt);
}

// void    set_rendered(t_game *game)
// {
//     game->rendered.img = mlx_new_image(game->mlx, game->config.res.x, game->config.res.y);
//     game->rendered.addr = mlx_get_data_addr(game->rendered.img, &game->rendered.bpp, &game->rendered.line_length, &game->rendered.endian);
//     game->rendered.bpp = 24;
    
// }

void	set_player(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->map->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' || map[y][x] == 'W' || map[y][x] == 'S')
			{
				game->player->position.x = x;
				game->player->position.y = y;
				game->start_position.x = x;
				game->start_position.y = y;
				set_player_utils(game, map, map[y][x]);
			}
		}
		y++;
	}
	game->player->camera_plane.x = 0;
	game->player->camera_plane.y = 0;
	game->player->movement_speed = PLAYER_SPEED;
	game->player->rotation_speed = ROTATION_SPEED;
}

void set_player_utils(t_game *game, char **map, char direction)
{
	if (direction == 'N')
	{
		game->player->direction.x = 0;
		game->player->direction.y = -1;
	}
	else if (direction == 'E')
	{
		game->player->direction.x = 1;
		game->player->direction.y = 0;
	}
	else if (direction == 'W')
	{
		game->player->direction.x = -1;
		game->player->direction.y = 0;
	}
	else if (direction == 'S')
	{
		game->player->direction.x = 0;
		game->player->direction.y = 1;
	}
}

// void    set_textures(t_game *game)
// {
//     int i;

//     i = 0;
//     while (i < 4)
//     {
//         sett_textures_utils(game->textures[i]);
//         i++;
//     }
// }

// void    set_textures_utils(t_texture *textures)
// {
//     game->textures->img = mlx_xpm_file_to_image(game->mlx, game->config.textures[NORTH], &game->textures[NORTH].width, &game->textures[NORTH].height);
//     game->textures->data = (int *)mlx_get_data_addr(game->textures[NORTH].img, &game->textures[NORTH].bpp, &game->textures[NORTH].line_length, &game->textures[NORTH].endian);
// }

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
        return (error_print(ALLOCATE_ERROR), free_game(game), exit(1), NULL);
    while (text[i])
    {
        j = 0;
        while (text[i][j] == ' ')
            j++;
        if (text[i][j] == '1')
        {
            map[k] = malloc(sizeof(char) * (map_width(text) + 1));
            if (!map[k])
                return (error_print(ALLOCATE_ERROR), free_game(game), exit(1), NULL);
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

void    set_ceil_floor(t_game *game)
{
    set_floor_color(game);
    set_ceiling_color(game);
    if (!game->floor_color || !game->ceiling_color)
        return (free_game(&game), exit(1), 0);
}

void    set_floor_color(t_game *game)
{
    size_t i;
    size_t j;
    int *tmp_f;

    i = 0;
    tmp_f = NULL;
    while (game->txt[i])
    {
        j = 0;
        while (game->txt[i][j] == ' ')
            j++;
        if (game->txt[i][j] == 'F')
        {
            j++;
            while (game->txt[i][j] == ' ')
                j++;
            tmp_f = parse_rgb(&(game->txt[i][j]));
			if (!tmp_f)
				return (free_game(&game), exit(1), 0);
        }
        i++;
    }
    if ((tmp_f[0] < COLOR_MIN || tmp_f[0] > COLOR_MAX || tmp_f[1] < COLOR_MIN || tmp_f[1] > COLOR_MAX || tmp_f[2] < COLOR_MIN || tmp_f[2] > COLOR_MAX))
    {
        free(tmp_f);
		error_print(INVALID_COLOR);
        return ;
    }
    game->floor_color = tmp_f[0] << 16 | tmp_f[1] << 8 | tmp_f[2];
}

void    set_ceiling_color(t_game *game)
{
    size_t i;
    size_t j;
    int *tmp_c;

    i = 0;
    tmp_c = NULL;
    while (game->txt[i])
    {
        j = 0;
        while (game->txt[i][j] == ' ')
            j++;
        if (game->txt[i][j] == 'C')
        {
            j++;
            while (game->txt[i][j] == ' ')
                j++;
            tmp_c = parse_rgb(&(game->txt[i][j]));
			if (!tmp_c)
				return (free_game(&game), exit(1), 0);
        }
        i++;
    }
    if ((tmp_c[0] < COLOR_MIN || tmp_c[0] > COLOR_MAX || tmp_c[1] < COLOR_MIN || tmp_c[1] > COLOR_MAX || tmp_c[2] < COLOR_MIN || tmp_c[2] > COLOR_MAX))
    {
        free(tmp_c);
		error_print(INVALID_COLOR);
        return ;
    }
    game->ceiling_color = tmp_c[0] << 16 | tmp_c[1] << 8 | tmp_c[2];
}

int	*parse_rgb(char *str)
{
	char **rgb;
	int *colors;

	colors = malloc(sizeof(int) * 3);
	if (!colors)
		return (error_print(ALLOCATE_ERROR), NULL);
	rgb = ft_split(str, ',');
	if (!rgb)
		return (free(colors), error_print(ALLOCATE_ERROR), NULL);
	colors[0] = ft_atoi(rgb[0]);
	colors[1] = ft_atoi(rgb[1]);
	colors[2] = ft_atoi(rgb[2]);
	free(rgb);
	return (colors);
}