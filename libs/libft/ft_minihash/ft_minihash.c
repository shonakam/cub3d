/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minihash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:01:35 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 11:42:55 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minihash.h"

void	init_minihash(t_minihash *map)
{
	int	i;

	i = 0;
	while (i < DEFAULT_HASH_SIZE)
	{
		map->table[i].key = EMPTY_KEY;
		map->table[i].value = 0;
		i++;
	}
}

void	minihash_set(t_minihash *map, int key, int value)
{
	int	index;
	int	i;
	int	idx;

	index = hash_function(key);
	i = 0;
	while (i < DEFAULT_HASH_SIZE)
	{
		idx = (index + i) % DEFAULT_HASH_SIZE;
		if (map->table[idx].key == EMPTY_KEY || map->table[idx].key == key)
		{
			map->table[idx].key = key;
			map->table[idx].value = value;
			return ;
		}
		i++;
	}
}

int	minihash_get(t_minihash *map, int key)
{
	int	index;
	int	i;
	int	idx;

	index = hash_function(key);
	i = 0;
	while (i < DEFAULT_HASH_SIZE)
	{
		idx = (index + i) % DEFAULT_HASH_SIZE;
		if (map->table[idx].key == key)
			return (map->table[idx].value);
		if (map->table[idx].key == EMPTY_KEY)
			return (0);
		i++;
	}
	return (0);
}

void	minihash_remove(t_minihash *map, int key)
{
	int	index;
	int	i;
	int	idx;

	index = hash_function(key);
	i = 0;
	while (i < DEFAULT_HASH_SIZE)
	{
		idx = (index + i) % DEFAULT_HASH_SIZE;
		if (map->table[idx].key == key)
		{
			map->table[idx].key = EMPTY_KEY;
			map->table[idx].value = 0;
			return ;
		}
		if (map->table[idx].key == EMPTY_KEY)
			return ;
		i++;
	}
}
