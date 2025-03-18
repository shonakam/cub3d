/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:33:01 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 00:35:05 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core_internal.h"

int	set_texture(t_cub3d *cub, t_texture *tex, char *path)
{
	int			bpp;
	int			line_length;
	int			endian;

	if (access(path, F_OK) == -1)
		exit_cub(cub, "Error: Texture file not found.", EXIT_FAILURE);
	tex->image.ptr = mlx_xpm_file_to_image(cub->mlx, path, &tex->width, &tex->height);
	if (!tex->image.ptr)
		exit_cub(cub, ERR_TEXTURE, EXIT_FAILURE);
	tex->image.data = mlx_get_data_addr(tex->image.ptr, &bpp, &line_length, &endian);
	tex->image.bpp = bpp;
	tex->image.line_length = line_length;
	tex->image.endian = endian;
	return (1);
}
