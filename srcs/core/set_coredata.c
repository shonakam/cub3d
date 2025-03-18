/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coredata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:07:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 21:47:05 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

static int	check_config_complete(t_config *config)
{
	if (!config->no_set || !config->so_set || !config->we_set || !config->ea_set)
		return (printf("Error: Missing wall texture.\n"), 1);
	if (!config->f_set || !config->c_set)
		return (printf("Error: Missing floor/ceiling color.\n"), 1);
	return (0);
}

static int	parse_config_line(t_cub3d *cub, t_config *config, char *line)
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

static int	detect_map_start(t_config *config, char *line)
{
	if (ft_isdigit(line[0]) || line[0] == ' ')
	{
		config->map_started = 1;
		return (1);
	}
	return (0);
}

static void	read_map_data(t_cub3d *cub, int fd, char *line)
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

int	set_coredata(t_cub3d *cub, int fd)
{
	char		*line;
	t_config	config;

	ft_memset(&config, 0, sizeof(t_config));
	line = get_next_line(fd);
	while (line)
	{
		if (!config.map_started)
		{
			if (parse_config_line(cub, &config, line))
			{
				free(line);
				line = get_next_line(fd);
				continue;
			}
			if (detect_map_start(&config, line))
			{
				if (check_config_complete(&config))
					return (free(line), exit_cub(cub, "Error: Incomplete configuration.", EXIT_FAILURE), 1);
				read_map_data(cub, fd, line);
				set_player(&cub->player, cub->map.col);
				set_fov(&cub->player, 60);
				return (0);
			}
			return (free(line), exit_cub(cub, "Error: Invalid .cub format.", EXIT_FAILURE), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (exit_cub(cub, "Error: Missing map data.", EXIT_FAILURE), 1);
}
