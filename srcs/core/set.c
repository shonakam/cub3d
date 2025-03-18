/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:07:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 20:35:10 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

int	set_coredata(t_cub3d *cub, int fd)
{
	char	*line;
	char	*new_line;

	line = get_next_line(fd);
	while (line && (!parse_texture(cub, line) || !parse_color(cub, line)))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		exit_cub(cub, "Cannot read map.", EXIT_FAILURE);
	while ((new_line = get_next_line(fd)))
	{
		line = join_n_free(line, new_line);
		free(new_line);
		if (!line)
			exit_cub(cub, "Failed to allocate memory.", EXIT_FAILURE);
	}
	cub->map.col = ft_split(line, '\n');
	free(line);
	if (check_map(cub))
		exit_cub(cub, "Invalid map.", EXIT_FAILURE);
	set_player(&cub->player, cub->map.col);
	set_fov(&cub->player, 60);
	return (0);
}

void	set_texture(t_cub3d *cub, t_texture *tex, char *path)
{
	int			bpp;
	int			line_length;
	int			endian;

	tex->image.ptr = mlx_xpm_file_to_image(cub->mlx, path, &tex->width, &tex->height);
	if (!tex->image.ptr)
		exit_cub(cub, "Failed to load texture.", EXIT_FAILURE);
	tex->image.data = mlx_get_data_addr(tex->image.ptr, &bpp, &line_length, &endian);
	tex->image.bpp = bpp;
	tex->image.line_length = line_length;
	tex->image.endian = endian;
}

int set_player(t_player *player, char **map)
{
	int x, y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSWE", map[y][x]))
			{
				player->position.x = x + 0.5;
				player->position.y = y + 0.5;
				player->direction.x = 0;
				player->direction.y = 0;
				if (map[y][x] == 'N')
					player->direction.y = -1;
				else if (map[y][x] == 'S')
					player->direction.y = 1;
				else if (map[y][x] == 'W')
					player->direction.x = -1;
				else if (map[y][x] == 'E')
					player->direction.x = 1;
				map[y][x] = '0';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	set_fov(t_player *player, double fov)
{
	double	plane_length;
	double	fov_radians = (fov * M_PI) / 180.0;

	plane_length = tan(fov_radians / 2);
	player->plane.x = -player->direction.y * plane_length;
	player->plane.y = player->direction.x * plane_length;
}
