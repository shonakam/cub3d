/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:22:40 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 19:01:04 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core_internal.h"

void	set_fov(t_player *player, double fov)
{
	double	plane_length;
	double	fov_radians;

	fov_radians = (fov * get_pi()) / 180.0;
	plane_length = tan(fov_radians / 2);
	player->plane.x = -player->direction.y * plane_length;
	player->plane.y = player->direction.x * plane_length;
}

// char	*read_map_data(int fd, t_cub3d *cub)
// {
// 	char	*line;
// 	char	*map_data;
// 	char	*new_line;

// 	map_data = get_next_line(fd);
// 	while (map_data 
// 		&& (!parse_texture(cub, map_data) || !parse_color(cub, map_data)))
// 	{
// 		free(map_data);
// 		map_data = get_next_line(fd);
// 	}
// 	if (!map_data)
// 		return (NULL);
// 	while ((new_line = get_next_line(fd)))
// 	{
// 		map_data = join_n_free(map_data, new_line);
// 		free(new_line);
// 		if (!map_data)
// 			return (NULL);
// 	}
// 	return (map_data);
// }
