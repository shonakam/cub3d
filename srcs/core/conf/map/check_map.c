/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:09:22 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 01:52:43 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../core_internal.h"

int	check_map(t_cub3d *cub)
{
	size_t len;

	cub->map.width = 0;
	cub->map.height = 0;
	while (cub->map.col[cub->map.height])
	{
		len = ft_strlen(cub->map.col[cub->map.height]);
		if (len > cub->map.width)
			cub->map.width = len;
		cub->map.height++;
	}
	if (check_char(cub))
		return (1);
	if (check_wall(cub))
		return (1);
	return (0);
}
