/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:42:32 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 05:53:19 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "cub3d_defines.h"
# include "libs/minilibx-linux/mlx.h"

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

/* texture[0-4] = N, S, W, E */
typedef struct s_game {
	void		*mlx;
	void		*win;
	t_image		rendered;
	t_player	player;
	char		**map;
	t_texture	textures[4];
	int			floor_color;
	int			ceiling_color;
}				t_game;

#endif /* CUB3D_H */