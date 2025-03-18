/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:01:08 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 01:29:20 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

static int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	parse_texture(t_cub3d *cub, t_config *conf, char *line)
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
		conf->no_set = set_texture(cub, &cub->textures[0], path);
	else if (ft_strnstr(line, "SO ", 3))
		conf->so_set = set_texture(cub, &cub->textures[1], path);
	else if (ft_strnstr(line, "WE ", 3))
		conf->we_set = set_texture(cub, &cub->textures[2], path);
	else if (ft_strnstr(line, "EA ", 3))
		conf->ea_set = set_texture(cub, &cub->textures[3], path);
	free(path);
	return (0);
}

static int	parse_color(t_cub3d *cub, t_config *conf, char *line)
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
		exit_cub(cub, ERR_COLOR, EXIT_FAILURE);
	color = create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	if (ft_strnstr(line, "F ", 2))
	{
		cub->floor_color = color;
		conf->f_set = 1;
	}
	else
	{
		cub->ceiling_color = color;
		conf->c_set = 1;
	}
	ft_free_split(rgb);
	return (0);
}

int	parse_config(t_cub3d *cub, t_config *config, char *line)
{
	parse_texture(cub, config, line);
	parse_color(cub, config, line);
	return (0);
}

