/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 00:00:43 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 10:52:58 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../core_internal.h"



int	set_map_data(t_cub3d *cub, int fd, char *line)
{
	char	*new_line;

	new_line = get_next_line(fd);
	while (new_line)
	{
		line = join_n_free(line, new_line);
		free(new_line);
		new_line = get_next_line(fd);
		if (!line)
			return (exit_cub(cub, ERR_ALLOC, EXIT_FAILURE), 1);
	}
	cub->map.col = ft_split(line, '\n');
	free(line);
	if (check_map(cub))
		return (exit_cub(cub, ERR_MAP, EXIT_FAILURE), 1);
	return (0);
}
