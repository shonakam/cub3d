/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:29:39 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 21:32:18 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

static int	set_player_direction(t_player *player, char direction)
{
	player->direction.x = 0;
	player->direction.y = 0;
	if (direction == 'N')
		player->direction.y = -1;
	else if (direction == 'S')
		player->direction.y = 1;
	else if (direction == 'W')
		player->direction.x = -1;
	else if (direction == 'E')
		player->direction.x = 1;
	return (1);
}

int	set_player(t_player *player, char **map)
{
	int		x;
	int		y;
	char	direction;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSWE", map[y][x]))
			{
				player->position.x = x + 0.5;
				player->position.y = y + 0.5;
				direction = map[y][x];
				map[y][x] = '0';
				return (set_player_direction(player, direction));
			}
			x++;
		}
		y++;
	}
	return (0);
}
