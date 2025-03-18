/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:07:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 18:59:49 by shonakam         ###   ########.fr       */
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
	set_player(&cub->player, cub->map.col);
	return (check_map(cub));
}

t_texture	*set_texture(t_cub3d *cub, char *path)
{
	t_texture	*texture;
	int			bpp;
	int			line_length;
	int			endian;

	texture->image.ptr = mlx_xpm_file_to_image(cub->mlx, path, &texture->width, &texture->height);
	if (!texture->image.ptr)
		exit_cub(cub, "Failed to load texture.", EXIT_FAILURE);
	texture->image.data = mlx_get_data_addr(texture->image.ptr, &bpp, &line_length, &endian);
	texture->image.bpp = bpp;
	texture->image.line_length = line_length;
	texture->image.endian = endian;
	return (texture);
}

int	parse_texture(t_cub3d *cub, char *line)
{
	char	*path;

	if (line[0] == '\n')
		return (0);
	if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "SO ", 3)
		|| ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "EA ", 3))
		path = ft_strtrim(line + 3, "\n");
	else
		return (1);
	if (!path)
		exit_cub(cub, "Failed to allocate memory.", EXIT_FAILURE);
	if (ft_strnstr(line, "NO ", 3))
		cub->textures[0] = *set_texture(cub, path);
	else if (ft_strnstr(line, "SO ", 3))
		cub->textures[1] = *set_texture(cub, path);
	else if (ft_strnstr(line, "WE ", 3))
		cub->textures[2] = *set_texture(cub, path);
	else if (ft_strnstr(line, "EA ", 3))
		cub->textures[3] = *set_texture(cub, path);
	free(path);
	return (0);
}

int parse_color(t_cub3d *cub, char *line)
{
	char	**rgb;
	int		color;

	if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "C ", 2))
		rgb = ft_split(line + 2, ',');
	else
		return (1);
	if (!rgb)
		exit_cub(cub, "Failed to allocate memory.", EXIT_FAILURE);
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		exit_cub(cub, "Invalid color.", EXIT_FAILURE);
	color = create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	if (ft_strnstr(line, "F ", 2))
		cub->floor_color = color;
	else
		cub->ceiling_color = color;
	free(rgb);
	return (0);
}

int set_player(t_player *player, char **map)
{
	int (x), (y) = 0;
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
