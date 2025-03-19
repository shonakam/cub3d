/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:31:17 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 13:47:43 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../core_internal.h"

static int	is_space_or_null(char c)
{
	return (c == ' ' || c == '\0');
}

static int	is_border(t_cub3d *cub, int i, int j)
{
	return (i == 0 || i == (int)cub->map.height - 1
		|| j == 0 || j == (int)cub->map.width - 1);
}

static int	has_adjacent_space(t_cub3d *cub, int i, int j)
{
	return (is_space_or_null(cub->map.col[i + 1][j])
		|| is_space_or_null(cub->map.col[i - 1][j])
		|| is_space_or_null(cub->map.col[i][j + 1])
		|| is_space_or_null(cub->map.col[i][j - 1]));
}

static int	is_invalid_wall(t_cub3d *cub, int i, int j)
{
	if (is_border(cub, i, j))
		return (cub->map.col[i][j] != '1' && cub->map.col[i][j] != ' ');
	if (cub->map.col[i][j] != '1' && cub->map.col[i][j] != ' ')
		return (has_adjacent_space(cub, i, j));
	return (0);
}

int	check_wall(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.col[i])
	{
		j = 0;
		while (cub->map.col[i][j])
		{
			if (is_invalid_wall(cub, i, j))
			{
				printf("Error: Invalid wall at (i=%d, j=%d)\n", i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
