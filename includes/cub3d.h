/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:42:32 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/05 04:15:59 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "libs/minilibx/mlx.h"
# include "libs/libft/libft.h"
# include "cub3d_defines.h"

/* coordinate */
typedef struct s_vector	{
	double	x;
	double	y;
}				t_vector;

typedef struct s_player {
	t_vector	position;          /* プレイヤーの現在位置 */
	t_vector	direction;         /* プレイヤーが向いている方向ベクトル */
	t_vector	camera_plane;      /* カメラの視野平面 */
	double		movement_speed;    /* プレイヤーの移動速度 */
	double		rotation_speed;    /* プレイヤーの回転速度 */
}				t_player;

// typedef struct s_image {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_length;
// 	int		endian;
// }				t_image;

typedef struct s_texture {
	void	*img;
	int		*data;
	int		width;
	int		height;
}				t_texture;

/* texture[0-4] = N, S, W, E */
typedef struct s_cub3d {
	void		*mlx;
	void		*win;
	// t_image		rendered;
	// t_player	player;
	char		**map;
	t_texture	textures[4];
	int			floor_color;
	int			ceiling_color;
}				t_cub3d;


t_cub3d		*initialize_cub(void);
int			set_coredata(t_cub3d *cub);
// void		start_game(t_cub3d *cub);

/* <=== SUPPORT ===> */
int			validate_extension(const char *file);

#endif /* CUB3D_H */