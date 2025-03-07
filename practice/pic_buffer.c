#include "../libs/minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
}   t_data;

void put_pixel_to_image(t_data *data, int x, int y, int color) {
    if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT) {
        char *dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
        *(unsigned int *)dst = color;
    }
}

void draw_wall_slice(t_data *data, int x, int start, int end, int color) {
    for (int y = start; y < end; y++) {
        put_pixel_to_image(data, x, y, color);
    }
}

void render(t_data *data) {
    for (int x = 0; x < WIN_WIDTH; x++) {
        int wall_start = 200;
        int wall_end = 400;
        draw_wall_slice(data, x, wall_start, wall_end, 0xFFFFFF); // 壁を描画
    }

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0); // **1回で描画**
}

int main() {
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Raycasting");
    data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_length, &data.endian);

    render(&data);
    
    mlx_loop(data.mlx);  // イベントループ
    return (0);
}
