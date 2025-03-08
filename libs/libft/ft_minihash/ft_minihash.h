/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minihash.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:53:59 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 10:31:30 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIHASH_H
# define FT_MINIHASH_H

# include "../libft.h"

# define DEFAULT_HASH_SIZE 128
# define EMPTY_KEY -1

typedef struct s_hashentry{
	int			key;
	int			value;
}				t_hashentry;

typedef struct s_minihash {
	t_hashentry	table[DEFAULT_HASH_SIZE];
}				t_minihash;

void	init_minihash(t_minihash *map);
void	minihash_set(t_minihash *map, int key, void *value);
void	*minihash_get(t_minihash *map, int key);
void	minihash_remove(t_minihash *map, int key);

void	free_minihash(t_minihash *map);
int		hash_function(int key);

#endif /* FT_MINIHASH_H */