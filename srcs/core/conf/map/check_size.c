/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:53:57 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 13:44:25 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../core_internal.h"

int	check_size(t_cub3d *cub)
{
	size_t	x;

	x = 0;
	while (cub->map.col[x])
	{
		if (ft_strlen(cub->map.col[x]) > MAP_MAX_WIDTH)
		{
			printf("Error: Invalid map size at line %zu\n", x);
			return (1);
		}
		if (x > MAP_MAX_HEIGHT)
		{
			printf("Error: Invalid map size. Too many lines.\n");
			return (1);
		}
		x++;
	}
	return (0);
}
