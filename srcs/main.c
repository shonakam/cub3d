/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:12:30 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/05 04:58:36 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	*cub;

	cub = NULL;
	if (ac != 2 || !validate_extension(av[1]))
		return (EXIT_FAILURE);
	cub = initialize_cub();
	if (!cub)
		return (EXIT_FAILURE);
	// if (!set_coredata(cub))
	// 	return (EXIT_FAILURE);
	// hadle_game(&cub);
	return (EXIT_SUCCESS);
}
