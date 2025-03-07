#include "../includes/cub3d.h"

void    init_game(t_game *game)
{
    game = malloc(sizeof(t_game));
    if (!game)
        return ;
    game->mlx =NULL;
    game->win = NULL;
    game->txt = NULL;
    init_rendered(game);
    init_map(game);
    init_player(game);
    init_textures(game);
    game->floor_color = 0;
    game->ceiling_color = 0;
}

void    init_rendered(t_game *game)
{
    game->rendered.img = NULL;
    game->rendered.addr = NULL;
    game->rendered.bpp = 0;
    game->rendered.line_length = 0;
    game->rendered.endian = 0;
}

void    init_player(t_game *game)
{
    game->player = malloc(sizeof(t_player));
    if (!game->player)
        return ;
    game->player.position.x = 0;
    game->player.position.y = 0;
    game->player.direction.x = 0;
    game->player.direction.y = 0;
    game->player.camera_plane.x = 0;
    game->player.camera_plane.y = 0;
    game->player.movement_speed = 0;
    game->player.rotation_speed = 0;
}

void    init_textures(t_game *game)
{
    int i;

    i = 0;
    while (i < 4)
    {
        game->textures[i].img = NULL;
        game->textures[i].data = NULL;
        game->textures[i].width = 0;
        game->textures[i].height = 0;
        i++;
    }
}

void   init_map(t_game *game)
{
    game->map = malloc(sizeof(t_map));
    if (!game->map)
        return ;
    game->map->map = NULL;
    game->map->width = 0;
    game->map->height = 0;
}