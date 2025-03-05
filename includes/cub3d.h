/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:42:32 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/06 03:18:56 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
// # include "libs/minilibx/mlx.h"
# include "libs/libft/libft.h"
# include "cub3d_defines.h"

/* coordinate */
typedef struct s_vector	{
	double	x;
	double	y;
}				t_vector;

typedef struct s_player {
	t_vector	position;          /* プレイヤーの現在位置 */
	t_vector	direction;        /* プレイヤーが向いている方向ベクトル */
	t_vector	camera_plane;      /* カメラの視野平面 */
	double		movement_speed;    /* プレイヤーの移動速度 */
	double		rotation_speed;    /* プレイヤーの回転速度 */
}				t_player;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_texture {
	void	*img;
	int		*data;
	int		width;
	int		height;
}				t_texture;

typedef struct s_map {
	char	**map;
	size_t	width;
	size_t	height;
}				t_map;

/* texture[0-4] = N, S, W, E */
typedef struct s_game {
	void		*mlx;
	void		*win;
	char		**txt;
	t_image		rendered;
	t_player	*player;
	t_map		*map;
	t_texture	textures[4];
	int			*floor_color;
	int			*ceiling_color;
	t_vector	start_position;
}				t_game;


typedef enum
{
    ALLOCATE_ERROR,
    OPEN_ERROR,
    INVALID_MAP,
	INVALID_TXT,
    MORE_THAN_ONE_PLAYER,
    NO_PLAYER,
    INVALID_TEXTURE,
    INVALID_COLOR,
    INVALID_RESOLUTION,
    INVALID_FILE_EXTENSION,
    INVALID_ARGUMENT,
    INVALID_FILE,
    INVALID_CONFIG,
    INVALID_MAP_CONFIG,
    INVALID_MAP_SIZE,
    INVALID_MAP_CHARACTER,
    INVALID_MAP_WALL,
    INVALID_MAP_SURROUND,
    INVALID_MAP_EMPTY,
    INVALID_MAP_LINE,
    INVALID_MAP_LINE_LENGTH,
    INVALID_MAP_LINE_CHARACTER,
    INVALID_MAP_LINE_WALL,
    INVALID_MAP_LINE_PLAYER,
    INVALID_MAP_LINE_SURROUND,
	NO_FLOOR_INFO,
	NO_CEILING_INFO
}   t_enum;

//init
void	init_game(t_game *game);
void	init_rendered(t_game *game);
void	init_map(t_game *game);
void	init_player(t_game *game);
void	init_textures(t_game *game);

//utils
void	error_print(t_enum error_num);
void	safe_free(void **ptr);
void	free_game(t_game **game);

//render
void	set_game(t_game *game, const char *file_path);
void	set_txt(t_game *game, const char *file_path);   
void	set_map(t_game *game);
void	set_rendered(t_game *game);
void	set_player(t_game *game);
void	set_player_utils(t_game *game, char **map, char direction);
void	set_textures(t_game *game);
void	set_textures_utils(t_texture *textures);
char	**map_setting(t_game *game, char **text);
void	set_ceil_floor(t_game *game);
void	set_floor_color(t_game *game);
void	set_ceiling_color(t_game *game);
int		*parse_rgb(char *str);

//condition
int		is_con_txt(t_game *game);
int		check_wall_textures(char **txt);
int		has_one_wall_info(char **txt, char *str);

int		is_con_map(char **map);
int		has_one_player(char **map);
int		surround_wall(char **map);
int		prohibited_c(char **map);

//measure
int		map_width(char **map);
int		map_height(char **map);


t_cub3d		*initialize_cub(void);
int			set_coredata(t_cub3d *cub);
// void		start_game(t_cub3d *cub);

/* <=== SUPPORT ===> */
int			validate_extension(const char *file);

#endif /* CUB3D_H */