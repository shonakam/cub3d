/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:43:39 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 01:49:14 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_INTERNAL_H
# define CORE_INTERNAL_H

# include <sys/time.h>
# include "../../includes/cub3d.h"

# define ERR_TEXTURE "Error: Failed to load texture."
# define ERR_COLOR "Error: Invalid color."
# define ERR_MAP "Error: Invalid map."
# define ERR_CONFIG "Error: Incomplete configuration."
# define ERR_ALLOC "Error: Failed to allocate memory."

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
int		check_wall(t_cub3d *cub);
int		check_char(t_cub3d *cub);
int		check_map(t_cub3d *cub);
void	set_fov(t_player *player, double fov);
int		set_player(t_player *player, char **map);
int		set_texture(t_cub3d *cub, t_texture *tex, char *path);

int		detect_map_start(t_config *config);
int		set_map_data(t_cub3d *cub, int fd, char *line);
int		parse_config(t_cub3d *cub, t_config *config, char *line);
int		set_coredata(t_cub3d *cub, int fd);

double	get_delta_time(void);
char	*join_n_free(char *s1, char *s2);
void	ft_free_split(char **arr);

#endif /* CORE_INTERNAL_H */