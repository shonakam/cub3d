/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:44:55 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 14:42:07 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_INTERNAL_H
# define DISPLAY_INTERNAL_H

# include "includes/cub3d.h"

typedef struct s_vec_i {
	int	x;
	int y;
}				t_vec_i;

typedef struct s_ray {
	double	screen_relative_x;
	t_vec_i	map;
	t_vec_d	pos;
	t_vec_d	direction;
	t_vec_i	step;
	t_vec_d	side_distance;
	t_vec_d	delta_distance;
	double	wall_hit_distance;
	int		hit;
	int		side;
}				t_ray;

typedef struct s_wall_render {
	int				line_height;
	int				draw_start;
	int				draw_end;
	t_vec_i			tex;
	double			wall_hit_x;
	int				tex_height;
	unsigned int	color;
	t_texture		*wall_texture;
}				t_wall_render;

void		draw_wall(t_image *img, t_ray *ray, int x, t_texture textures[4]);
void		draw_ceiling(t_image *img, t_cub3d *cub, int x, int start);
void		draw_floor(t_image *img, t_cub3d *cub, int x, int end);
int			get_texture_pixel(t_texture *texture, t_vec_i tex);
t_texture	*set_wall_texture(t_ray *ray, t_texture textures[4]);
void		clamp_wall_draw_range(t_wall_render *wall);
int			calculate_texture_x(t_ray *ray, t_wall_render *wall);

void		perform_dda(t_cub3d *cub, t_ray *ray);
void		init_ray(t_cub3d *cub, t_ray *ray, int x);

void		put_pixel_to_image(t_image *img, int x, int y, int color);

#endif /* DISPLAY_INTERNAL_H */