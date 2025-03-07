/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:53:18 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/07 12:40:40 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

t_cub3d	*initialize_cub(void)
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
