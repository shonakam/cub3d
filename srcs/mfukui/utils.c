#include "../includes/cub3d.h"

void error_print(t_enum error_num)
{
    printf("Error\n");
    if (error_num == ALLOCATE_ERROR)
        printf("Failed to allocate memory\n");
    else if (error_num == OPEN_ERROR)
        printf("Failed to open file\n");
    else if (error_num == INVALID_MAP)
        printf("Invalid map\n");
    else if (error_num == MORE_THAN_ONE_PLAYER)
        printf("There are more than one player\n");
    else if (error_num == NO_PLAYER)
        printf("There is no player\n");
    else if (error_num == INVALID_TEXTURE)
        printf("Invalid texture\n");
    else if (error_num == INVALID_COLOR)
        printf("Invalid color\n");
    else if (error_num == INVALID_TXT)
        printf("Invalid txt\n");
    else if (error_num == INVALID_RESOLUTION)
        printf("Invalid resolution\n");
    else if (error_num == INVALID_FILE_EXTENSION)
        printf("Invalid file extension\n");
    else if (error_num == INVALID_ARGUMENT)
        printf("Invalid argument\n");
    else if (error_num == INVALID_FILE)
        printf("Invalid file\n");
    else if (error_num == INVALID_MAP_CONFIG)
        printf("Invalid map config\n");
    else if (error_num == INVALID_MAP_SIZE)
        printf("Invalid map size\n");
    else if (error_num == INVALID_MAP_CHARACTER)
        printf("Invalid map character\n");
    else if (error_num == INVALID_MAP_WALL)
        printf("Invalid map wall\n");
    else if (error_num == INVALID_MAP_PLAYER)
        printf("Invalid map player\n");
    else if (error_num == INVALID_MAP_SURROUND)
        printf("Invalid map surround\n");
    else if (error_num == INVALID_MAP_PROHIBITED)
        printf("Invalid map prohibited\n");
    else if (error_num == INVALID_MAP_EMPTY)
        printf("Invalid map empty\n");
    else if (error_num == INVALID_MAP_LINE)
        printf("Invalid map line\n");
    else if (error_num == INVALID_MAP_LINE_LENGTH)
        printf("Invalid map line length\n");
    else if (error_num == INVALID_MAP_LINE_CHARACTER)
        printf("Invalid map line character\n");
    else if (error_num == INVALID_MAP_LINE_WALL)
        printf("Invalid map line wall\n");
    else if (error_num == INVALID_MAP_LINE_PLAYER)
        printf("Invalid map line player\n");
    else if (error_num == INVALID_MAP_LINE_SURROUND)
        printf("Invalid map line surround\n");
    else if (error_num == NO_FLOOR_INFO)
        printf("No floor infomation\n");
    else if (error_num == NO_CEILING_INFO)
        printf("No ceiling infomation\n");
}

void    safe_free(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

void    free_game(t_game **game)
{
	size_t	i;

	if (!game || !*game)
		return ;
	if ((*game)->txt)
	{
		i = 0;
		while ((*game)->txt[i])
			safe_free((void **)&((*game)->txt[i++]));
		safe_free((void **)&((*game)->txt));
	}
	if ((*game)->map)
	{
		i = 0;
		while ((*game)->map->map[i])
			safe_free((void **)&((*game)->map->map[i++]));
		safe_free((void **)&((*game)->map));
	}
	if ((*game)->player)
		safe_free((void **)&((*game)->player));
	if ((*game)->textures)
	{
		i = 0;
		while (i < 4)
			safe_free((void **)&((*game)->textures[i++].data));
	}
	if ((*game)->floor_color)
		safe_free((void **)&((*game)->floor_color));
	if ((*game)->ceiling_color)
		safe_free((void **)&((*game)->ceiling_color));
	if ((*game)->mlx && (*game)->win)
		(*game)->win = NULL;
	if ((*game)->mlx)
		safe_free((void **)&((*game)->mlx));
	safe_free((void **)game);
}
