/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:53:20 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 21:56:26 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

int	parse_config_line(t_cub3d *cub, t_config *config, char *line)
{
	if (ft_strnstr(line, "NO ", 3) && (config->no_set = 1))
		parse_texture(cub, line);
	else if (ft_strnstr(line, "SO ", 3) && (config->so_set = 1))
		parse_texture(cub, line);
	else if (ft_strnstr(line, "WE ", 3) && (config->we_set = 1))
		parse_texture(cub, line);
	else if (ft_strnstr(line, "EA ", 3) && (config->ea_set = 1))
		parse_texture(cub, line);
	else if (ft_strnstr(line, "F ", 2) && (config->f_set = 1))
		parse_color(cub, line);
	else if (ft_strnstr(line, "C ", 2) && (config->c_set = 1))
		parse_color(cub, line);
	else
		return (0);
	return (1);
}

int	detect_map_start(t_config *config, char *line)
{
	if (ft_isdigit(line[0]) || line[0] == ' ')
	{
		config->map_started = 1;
		return (1);
	}
	return (0);
}

void	read_map_data(t_cub3d *cub, int fd, char *line)
{
	char	*new_line;

	new_line = get_next_line(fd);
	while (new_line)
	{
		line = join_n_free(line, new_line);
		free(new_line);
		new_line = get_next_line(fd);
		if (!line)
			exit_cub(cub, "Failed to allocate memory.", EXIT_FAILURE);
	}
	cub->map.col = ft_split(line, '\n');
	free(line);
	if (check_map(cub))
		exit_cub(cub, "Invalid map.", EXIT_FAILURE);
}