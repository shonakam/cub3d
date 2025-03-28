/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coredata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:07:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/20 15:03:49 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

int	set_coredata(t_cub3d *cub, int fd)
{
	char		*line;
	t_config	config;

	ft_memset(&config, 0, sizeof(t_config));
	line = get_next_line(fd);
	while (line)
	{
		ft_rm_newline(line);
		if (!config.map_started)
		{
			parse_config(cub, &config, line);
			detect_map_start(&config);
		}
		else
		{
			if (set_map_data(cub, fd, line))
				return (1);
			set_player(&cub->player, cub->map.col);
			set_fov(&cub->player, 60);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (exit_cub(cub, "Error: Missing map data.", EXIT_FAILURE), 1);
}
