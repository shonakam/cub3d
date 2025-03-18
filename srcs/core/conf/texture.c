/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:33:01 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 21:37:59 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

static void	load_texture(t_cub3d *cub, t_texture *tex, char *path)
{
	int	bpp;
	int	line_length;
	int	endian;

	if (!cub || !tex || !path)
		exit_cub(cub, "Error: Invalid texture parameters.", EXIT_FAILURE);
	if (access(path, F_OK) == -1)
		exit_cub(cub, "Error: Texture file not found.", EXIT_FAILURE);
	tex->image.ptr = mlx_xpm_file_to_image(cub->mlx, path, &tex->width, &tex->height);
	if (!tex->image.ptr)
		exit_cub(cub, "Error: Failed to load texture.", EXIT_FAILURE);
	tex->image.data = mlx_get_data_addr(tex->image.ptr, &bpp, &line_length, &endian);
	tex->image.bpp = bpp;
	tex->image.line_length = line_length;
	tex->image.endian = endian;
}

static int	get_texture_index(char *line)
{
	if (ft_strnstr(line, "NO ", 3))
		return (0);
	if (ft_strnstr(line, "SO ", 3))
		return (1);
	if (ft_strnstr(line, "WE ", 3))
		return (2);
	if (ft_strnstr(line, "EA ", 3))
		return (3);
	return (-1);
}

int	parse_texture(t_cub3d *cub, char *line)
{
	char	*path;
	int		index;

	if (!line || line[0] == '\n')
		return (0);
	index = get_texture_index(line);
	if (index == -1)
		return (1);
	path = ft_strtrim(line + 3, "\n");
	if (!path)
		exit_cub(cub, ERR_TEXTURE, EXIT_FAILURE);
	load_texture(cub, &cub->textures[index], path);
	free(path);
	return (0);
}
