#include "../includes/cub3d.h"

int main()
{
    t_game *game;

    init_game(game);
    set_game(game);
    //実行
    free_game(&game);
    return (0);
}