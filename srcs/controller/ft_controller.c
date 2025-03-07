/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:16:42 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 08:53:24 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "controller_internal.h"

void	setup_cub(t_cub3d *cub);

int	ft_controller(int key, void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	printf("key: %d\n", key);
	return (0);
}

int main(void)
{
	t_cub3d *cub = initialize_cub();


	setup_cub(cub);
	cub->win = mlx_new_window(cub->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");

	mlx_key_hook(cub->win, ft_controller, cub);
	mlx_loop(cub->mlx);
	return (0);
}