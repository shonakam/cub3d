/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:07:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 17:38:15 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

int	set_coredata(t_cub3d *cub, int fd)
{
	char	*line;
	char	*new_line;

    line = get_next_line(fd);
    while (line && (!parse_texture(cub, line) || !parse_color(cub, line)))
    {
        free(line);
        line = get_next_line(fd);
    }
    if (!line)
        exit_cub(cub, "Cannot read map.", EXIT_FAILURE);
    while ((new_line = get_next_line(fd)))
    {
        line = join_n_free(line, new_line);
        free(new_line);
        if (!line)
            exit_cub(cub, "Failed to allocate memory.", EXIT_FAILURE);
    }
    cub->map.col = ft_split(line, '\n');
    free(line);
    return (check_map(cub));
}

t_texture    *set_texture(t_cub3d *cub, char *path)
{
    t_texture	*texture;
    int			bpp;
    int			line_length;
    int			endian;

    texture = (t_texture *)malloc(sizeof(t_texture));
    if (!texture)
        exit_cub(cub, "Failed to allocate memory.", EXIT_FAILURE);
    texture->image.ptr = mlx_xpm_file_to_image(cub->mlx, path, &texture->width, &texture->height);
    if (!texture->image.ptr)
        exit_cub(cub, "Failed to load texture.", EXIT_FAILURE);
    texture->image.data = mlx_get_data_addr(texture->image.ptr, &bpp, &line_length, &endian);
    texture->image.bpp = bpp;
    texture->image.line_length = line_length;
    texture->image.endian = endian;
    return (texture);
}

int	parse_texture(t_cub3d *cub, char *line)
{
	char	*path;

    if (line[0] == '\n')
        return (0);
    if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "SO ", 3)
        || ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "EA ", 3))
        path = ft_strtrim(line + 3, "\n");
    else
        return (1);
    if (!path)
        exit_cub(cub, "Failed to allocate memory.", EXIT_FAILURE);
    if (ft_strnstr(line, "NO ", 3))
        cub->textures[0] = *set_texture(cub, path);
    else if (ft_strnstr(line, "SO ", 3))
        cub->textures[1] = *set_texture(cub, path);
    else if (ft_strnstr(line, "WE ", 3))
        cub->textures[2] = *set_texture(cub, path);
    else if (ft_strnstr(line, "EA ", 3))
        cub->textures[3] = *set_texture(cub, path);
    free(path);
    return (0);
}

int parse_color(t_cub3d *cub, char *line)
{
	char	**rgb;
	int		color;

    if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "C ", 2))
        rgb = ft_split(line + 2, ',');
    else
        return (1);
    if (!rgb)
        exit_cub(cub, "Failed to allocate memory.", EXIT_FAILURE);
    if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
        exit_cub(cub, "Invalid color.", EXIT_FAILURE);
    color = create_trgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
    if (ft_strnstr(line, "F ", 2))
        cub->floor_color = color;
    else
        cub->ceiling_color = color;
    free(rgb);
    return (0);
}

char	*join_n_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1)
	{
		if (!*s2)
			return (NULL);
		s1 = ft_substr("", 0, 1);
	}
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	j = -1;
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	free(s1);
	return (dst);
}
