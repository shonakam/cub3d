/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:06:31 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 09:32:07 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	free_cub(t_cub3d *cub)
{
	size_t i;

	i = 0;
	while (i < cub->map.height)
		free(cub->map.col[i++]);
	free(cub->map.col);
	i = 0;
	while (i < 4)
	{
		if (cub->textures[i].image.ptr)
			mlx_destroy_image(cub->mlx, cub->textures[i].image.ptr);
	}
	mlx_destroy_window(cub->mlx, cub->win);
	free(cub);
}

void	exit_cub(t_cub3d *cub, const char *message, int status)
{
	if (message)
		ft_putendl_fd(message, STDERR_FILENO);
	free_cub(cub);
	exit(status);
}

