/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:16:42 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 13:01:34 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "includes/controller.h"

int	key_press(int key, void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	cub->last_key = key;
	minihash_set(&cub->keys, key, 1);
	return (0);
}

int	key_release(int key, void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	minihash_set(&cub->keys, key, 0);
	return (0);
}

/* Assign an action callback function based on key input */
int	ft_controller(int key, void *param)
{
	t_cub3d	*cub;

	cub = (t_cub3d *)param;
	if (key == KEY_ESC)
		exit_cub(cub, "Escape key pressed, exiting...", 0);
	else if (key == KEY_W)
		cub->action = move_forward;
	else if (key == KEY_S)
		cub->action = move_backward;
	else if (key == KEY_A)
		cub->action = move_left;
	else if (key == KEY_D)
		cub->action = move_right;
	else if (key == KEY_RIGHT)
		cub->action = rotate_right;
	else if (key == KEY_LEFT)
		cub->action = rotate_left;
	return (0);
}

