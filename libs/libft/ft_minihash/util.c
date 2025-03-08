/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:27:28 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 10:29:08 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minihash.h"

int	hash_function(int key)
{
	return (key % DEFAULT_HASH_SIZE);
}

void	free_minihash(t_minihash *map)
{
	int i; 

	i = 0;
	while (i < DEFAULT_HASH_SIZE)
	{
		if (map->table[i].value)
			free(map->table[i].value);
	}
}
