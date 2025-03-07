/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:53:18 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 08:46:37 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

static t_cub3d	*create_cub(void)
{
	t_cub3d	*cub;
	int		i;

	cub = malloc(sizeof(t_cub3d));
	if (!cub)
	{
		perror("Error: Failed to allocate memory for cub3d\n");
		return (NULL);
	}
	cub->mlx = NULL;
	cub->win = NULL;
	cub->floor_color = -1;
	cub->ceiling_color = -1;
	i = 0;
	while (i < 4)
	{
		cub->textures[i].image.ptr = NULL;
		cub->textures[i].image.data = NULL;
		i++;
	}
	return (cub);
}

t_cub3d		*initialize_cub(void)
{
	t_cub3d	*cub;

	cub = create_cub();
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
