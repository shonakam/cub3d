/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:04:16 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/05 00:53:58 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/mlx.h"

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 800, 600, "cub3D");
	mlx_string_put(mlx, win, 350, 300, 0xFFFFFF, "Hello");
	mlx_loop(mlx);
	return (0);
}

