/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 09:21:06 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 10:39:54 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/controller.h"

void	process_game(void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	ft_controller(cub);
	ft_statehandler(cub);
	ft_render(cub);
}

void	run_cub3d(void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	mlx_hook(cub->win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, key_release, cub);
	mlx_loop_hook(cub->mlx, process_game, cub);
	mlx_loop(cub->mlx);
}
