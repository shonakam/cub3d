/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:43:39 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 16:26:42 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_INTERNAL_H
# define CORE_INTERNAL_H

# include <sys/time.h>
# include "includes/cub3d.h"

int		set_coredata(t_cub3d *cub, int fd);
int		parse_texture(t_cub3d *cub, char *line);
int		parse_color(t_cub3d *cub, char *line);
char    *join_n_free(char *s1, char *s2);

int		check_map(t_cub3d *cub);
int		check_char(t_cub3d *cub);
int		check_wall(t_cub3d *cub);
int     count_char(char **map, char c);

void    free_map(t_map *map);
void    free_mlx(t_cub3d *cub);
void    free_cub(t_cub3d *cub);
void    exit_cub(t_cub3d *cub, const char *message, int status);

void    init_minihash_keys(t_minihash *keys);
void    init_textures(t_texture *textures);
void    init_cub_structure(t_cub3d *cub);
t_cub3d *allocate_cub(void);
t_cub3d *initialize_cub(void);

double	get_delta_time(void);
int     create_trgb(int t, int r, int g, int b);
char    *remove_char(char *str, char c);

#endif /* CORE_INTERNAL_H */