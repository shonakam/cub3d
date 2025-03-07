/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:42:32 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 08:41:18 by shonakam         ###   ########.fr       */
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
typedef struct s_vec_d	{
	double	x;
	double	y;
}				t_vec_d;

typedef struct s_player {
	t_vec_d	position;
	t_vec_d	direction;
	t_vec_d	plane;
	double	movement_speed;
	double	rotation_speed;
}				t_player;

typedef struct s_image {
	void	*ptr;
	char	*data;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_texture {
	t_image	image;
	int		width;
	int		height;
}				t_texture;

/* start -> [x, y, direction] */
typedef struct s_map {
	char	**col;
	size_t	width;
	size_t	height;
	size_t	start[3];
}				t_map;

/* texture[0-4] = N, S, W, E */
typedef struct s_cub3d {
	void		*mlx;
	void		*win;
	char		*txt;
	t_image		rendered;
	t_player	player;
	t_map		map;
	t_texture	textures[4];
	int			floor_color;
	int			ceiling_color;
}				t_cub3d;

t_cub3d		*initialize_cub(void);
int			set_coredata(t_cub3d *cub);

/* render() - Responsible for managing overall rendering
* - Draws the ceiling (C) and floor (F)
* - Calls raycaster() to render 3D walls
* - Draws the minimap (if applicable)
* - Finally, updates the window using mlx_put_image_to_window()
*/
void		ft_render(t_cub3d *cub);

void		free_cub(t_cub3d *cub);
/* <=== SUPPORT ===> */
int			validate_extension(const char *file);

#endif /* CUB3D_H */