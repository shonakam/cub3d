/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:06:31 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 16:29:00 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

/* Free the map structure */
void	free_map(t_map *map)
{
	size_t	i;

	if (!map || !map->col)
		return ;
	i =0;
	while (i < map->height)
	{
		if (map->col[i])
			free(map->col[i]);
		i++;
	}
	free(map->col);
	map->col = NULL;
}

/* Free MLX resources */
void	free_mlx(t_cub3d *cub)
{
	if (!cub || !cub->mlx)
		return;
	#ifdef __linux__
	mlx_destroy_display(cub->mlx);
	#endif
	free(cub->mlx);
	cub->mlx = NULL;
}

/* Free cub3d structure */
void	free_cub(t_cub3d *cub)
{
	size_t	i;

	if (!cub)
		return ;
	free_map(&cub->map);
	if (cub->win)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		cub->win = NULL;
	}
	free_mlx(cub);
	free(cub);
}

/* Exit cub3d safely */
void	exit_cub(t_cub3d *cub, const char *message, int status)
{
	if (message)
		ft_putendl_fd(message, STDERR_FILENO);
	if (cub && cub->mlx)
		mlx_loop_end(cub->mlx);
	free_cub(cub);
	exit(status);
}


