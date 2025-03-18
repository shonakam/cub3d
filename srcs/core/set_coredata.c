/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coredata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:07:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 21:56:00 by shonakam         ###   ########.fr       */
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
