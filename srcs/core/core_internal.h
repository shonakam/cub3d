/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:43:39 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 21:42:15 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_INTERNAL_H
# define CORE_INTERNAL_H

# include <sys/time.h>
# include "includes/cub3d.h"

# define ERR_TEXTURE "Error: Failed to load texture."

typedef struct s_config
{
	int	no_set;
	int	so_set;
	int	we_set;
	int	ea_set;
	int	f_set;
	int	c_set;
	int	map_started;
}				t_config;


/* <=== CONFIG ===> */
void	set_fov(t_player *player, double fov);
int		parse_texture(t_cub3d *cub, char *line);
int		parse_color(t_cub3d *cub, char *line);
char	*read_map_data(int fd, t_cub3d *cub);


int		set_coredata(t_cub3d *cub, int fd);

char	*join_n_free(char *s1, char *s2);

int		check_map(t_cub3d *cub);
int		check_char(t_cub3d *cub);
int		check_wall(t_cub3d *cub);
int		count_char(char **map, char c);

void	free_map(t_map *map);
void	free_mlx(t_cub3d *cub);
void	free_cub(t_cub3d *cub);
void	exit_cub(t_cub3d *cub, const char *message, int status);

double	get_delta_time(void);
int		create_trgb(int t, int r, int g, int b);
int		set_player(t_player *player, char **map);

#endif /* CORE_INTERNAL_H */