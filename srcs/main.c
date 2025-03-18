/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:12:30 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 01:56:55 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	d()
{
	printf("<=== DEBUG ===>\n");
}

void	print_map(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (cub->map.col[i])
	{
		printf("%s\n", cub->map.col[i]);
		i++;
	}
}

// void	print_texture_path(t_cub3d *cub)
// {
// 	printf("NO: %s\n", cub->textures[0].image.ptr);
// 	printf("SO: %s\n", cub->textures[1].image.ptr);
// 	printf("WE: %s\n", cub->textures[2].image.ptr);
// 	printf("EA: %s\n", cub->textures[3].image.ptr);
// }

void	print_player(t_cub3d *cub)
{
	printf("player position: %f, %f\n", cub->player.position.x, cub->player.position.y);
	printf("player direction: %f, %f\n", cub->player.direction.x, cub->player.direction.y);
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
		print_player(cub);
		exit_cub(cub, "ERR.", EXIT_FAILURE);
	}
	run_cub3d(cub);
}
