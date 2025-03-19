/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 01:32:07 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 13:39:31 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../core_internal.h"

static int	is_valid_map_char(char c)
{
	return (c == '1'
		|| c == '0' || c == 'N' || c == 'W'
		|| c == 'E' || c == 'S' || c == ' ');
}

static int	count_char(char **map, char c)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	num = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				num++;
			j++;
		}
		i++;
	}
	return (num);
}

static int	count_players(char **map)
{
	return (count_char(map, 'N')
		+ count_char(map, 'W')
		+ count_char(map, 'E')
		+ count_char(map, 'S'));
}

int	check_char(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.col[i])
	{
		j = 0;
		while (cub->map.col[i][j])
		{
			if (!is_valid_map_char(cub->map.col[i][j]))
			{
				printf("Invalid character in map: %c\n",
					cub->map.col[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (count_players(cub->map.col) != 1)
		return (1);
	return (0);
}
