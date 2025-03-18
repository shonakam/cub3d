/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:21:06 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 16:31:33 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/controller.h"

int	process_game(void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	if (!cub)
		return (0); 
	if (cub->last_key)
	{
		ft_controller(cub->last_key, cub);
		cub->last_key = -1;
	}
	if (cub->action)
	{
		cub->action(cub);
		cub->action = NULL;
	}
	ft_render(cub);
	return (0);
}

void	run_cub3d(t_cub3d *cub)
{
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!cub->win)
	{
		ft_putendl_fd(stderr, "Error: Failed to create window.");
		exit(1);
	}
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_release, cub);
	mlx_loop_hook(cub->mlx, process_game, cub);
	mlx_loop(cub->mlx);
}
