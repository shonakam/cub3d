/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:12:30 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 14:19:13 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	d(void)
{
	printf("<=== DEBUG ===>\n");
}

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
		return (ft_putendl_fd(ERROR_INVALID_FILE, 2), EXIT_FAILURE);
	cub = initialize_cub();
	if (!cub)
		return (ft_putendl_fd(ERROR_MALLOC, 2), EXIT_FAILURE);
	if (set_coredata(cub, open(av[1], O_RDONLY)))
	{
		exit_cub(cub, "ERR.", EXIT_FAILURE);
	}
	run_cub3d(cub);
}
