/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:53:18 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 12:19:20 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

static void init_minihash_keys(t_minihash *keys)
{
	*keys = (t_minihash){0};
	init_minihash(keys);
}

static void init_textures(t_texture *textures)
{
	for (int i = 0; i < 4; i++)
	{
		textures[i].image.ptr = NULL;
		textures[i].image.data = NULL;
	}
}

static void init_cub_structure(t_cub3d *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->floor_color = -1;
	cub->ceiling_color = -1;
	cub->last_key = -1;
	cub->action = NULL;
	init_minihash_keys(&cub->keys);
	cub->player = (t_player){0};
	cub->map = (t_map){0};
	init_textures(cub->textures);
}

static t_cub3d *allocate_cub(void)
{
	t_cub3d *cub = malloc(sizeof(t_cub3d));
	if (!cub)
	{
		perror("Error: Failed to allocate memory for cub3d\n");
		return (NULL);
	}
	init_cub_structure(cub);
	return cub;
}

t_cub3d		*initialize_cub(void)
{
	t_cub3d	*cub;

	cub = allocate_cub();
	if (!cub)
		return (NULL);
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		perror("Error: Failed to initialize mlx\n");
		free(cub);
		return (NULL);
	}
	setup_cub(cub);
	return (cub);
}
