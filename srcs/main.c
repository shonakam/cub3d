/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:12:30 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 09:20:48 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int	validate_extension(const char *file)
{
	const char	*ext;

	if (!file)
		return (0);
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".cub", 5) != 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_cub3d	*cub;

	cub = NULL;
	if (ac != 2 || !validate_extension(av[1]))
		return (EXIT_FAILURE);
	cub = initialize_cub();
	if (!cub)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
