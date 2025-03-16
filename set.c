/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:07:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/05 04:10:36 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

int	set_coredata(t_cub3d *cub, int fd)
{
    char	*line;
    char	*new_line;

    line = get_next_line(fd);
    while (line && !parse_texture(cub, line))
    {
        free(line);
        line = get_next_line(fd);
    }
    while (line && !parse_color(cub, line))
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
    line = remove_char(line, '\r');
    cub->map.col = ft_split(line, '\n');
    free(line);
    return (check_map(cub));
}

int	parse_texture(t_cub3d *cub, char *line)
{
    char	*path;

    if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "SO ", 3)
        || ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "EA ", 3))
        path = ft_strtrim(line + 3, "\n");
    else
        return (1);
    if (!path)
        exit_cub(cub, "Failed to allocate memory.", EXIT_FAILURE);
    if (ft_strnstr(line, "NO ", 3))
        cub->textures[0].image.ptr = mlx_xpm_file_to_image(cub->mlx, path, &cub->textures[0].width, &cub->textures[0].height);
    else if (ft_strnstr(line, "SO ", 3))
        cub->textures[1].image.ptr = mlx_xpm_file_to_image(cub->mlx, path, &cub->textures[1].width, &cub->textures[1].height);
    else if (ft_strnstr(line, "WE ", 3))
        cub->textures[2].image.ptr = mlx_xpm_file_to_image(cub->mlx, path, &cub->textures[2].width, &cub->textures[2].height);
    else if (ft_strnstr(line, "EA ", 3))
        cub->textures[3].image.ptr = mlx_xpm_file_to_image(cub->mlx, path, &cub->textures[3].width, &cub->textures[3].height);
    free(path);
    return (0);
}

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
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
    if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3] || !is_number(rgb[0]) || !is_number(rgb[1]) || !is_number(rgb[2]))
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

char	*remove_char(char *str, char c)
{
	int (i) = 0;
	int (j) = 0;
	while (str[i])
		if (str[i++] != c)
			j++;
	char *(new_str) = (char *)malloc(sizeof(char) * (j + 1));
	if (!new_str)
		end_game(NULL, EXIT_FAILURE, "Failed to allocate memory.");
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

int	count_char(char **map, char c)
{
    int	num;
    int	i;
    int	j;

    i = 0;
    num = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                num++;
            j++;
        }
        i++;
    }
    return (num);
}

int	check_map(t_cub3d *cub)
{
    int len;
    cub->map.width = 0;
    cub->map.height = 0;
    while (cub->map.col[cub->map.height])
    {
        len = (int)ft_strlen(cub->map.col[cub->map.height]);
        if (len > cub->map.width)
            cub->map.width = len;
        cub->map.height++;
    }
    if (check_char(cub))
        return (1);
    if (check_wall(cub))
        return (1);
    return (0);
}

int	check_char(t_cub3d *cub)
{
    char    valid[7] = {'1', '0', 'N', 'W', 'E', 'S', ' '};
    int	    i;
    int	    j;

    i = 0;
    while (cub->map.col[i])
    {
        j = 0;
        while (cub->map.col[i][j])
        {
            if (!ft_strchr(valid, cub->map.col[i][j]) && printf("Invalid character in map: %c\n", cub->map.col[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    if (count_char(cub->map.col, 'N') + count_char(cub->map.col, 'W')
        + count_char(cub->map.col, 'E') + count_char(cub->map.col, 'S') != 1)
    {
        return (1);
    }
    return (0);
}

int	check_wall(t_cub3d *cub)
{
    int	i;
    int	j;

    i = 0;
    while (cub->map.col[i])
    {
        j = 0;
        while (cub->map.col[i][j])
        {
            if (i == 0 || i == cub->map.height - 1 || j == 0
                || j == cub->map.width - 1)
            {
                if (cub->map.col[i][j] != '1' && cub->map.col[i][j] != ' ')
                    return (printf("i = %d, j = %d\n", i, j));
            }
            else if (cub->map.col[i][j] != '1' && cub->map.col[i][j] != ' ')
            {
                if (cub->map.col[i + 1][j] == ' ' || cub->map.col[i][j + 1] == ' '
                    || cub->map.col[i - 1][j] == ' ' || cub->map.col[i][j - 1] == ' ')
                    return (printf("i = %d, j = %d\n", i, j));
            }
            j++;
        }
        i++;
    }
    return (0);
}
