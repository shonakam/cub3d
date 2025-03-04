#include "../includes/cub3d.h"

int is_con_txt(char **txt)
{
    if (con_floor_ceiling(txt) == 0)
        return (0);
    if (is_con_wall(txt) == 0)
        return (0);
	
    return (1);
}

int *parse_rgb(char *str)
{
    char **rgb;
    int *colors;
    
    colors = malloc(sizeof(int) * 3);
    if (!colors)
        return (NULL);
    rgb = ft_split(str, ',');
    if (!rgb)
        return (free(colors), NULL);
    
    colors[0] = ft_atoi(rgb[0]);
    colors[1] = ft_atoi(rgb[1]);
    colors[2] = ft_atoi(rgb[2]);

    free(rgb);
    return (colors);
}

int con_floor_ceiling(char **txt)
{
    size_t i;
    size_t j;
    int *tmp_f;
    int *tmp_c;

    i = 0;
    tmp_c = NULL;
    tmp_f = NULL;
    while (txt[i])
    {
        j = 0;
        while (txt[i][j] == ' ')
            j++;
        if (txt[i][j] == 'F')
        {
            j++;
            while (txt[i][j] == ' ')
                j++;
            tmp_f = parse_rgb(&(txt[i][j]));
        }
        else if (txt[i][j] == 'C')
        {
            j++;
            while (txt[i][j] == ' ')
                j++;
            tmp_c = parse_rgb(&(txt[i][j]));
        }
        i++;
    }
    if (!tmp_f && !tmp_c)
        return (0);
    else if (!tmp_f)
        return (free(tmp_c), 0);
    else if (!tmp_c)
        return (free(tmp_f), 0);
    if ((tmp_f[0] < 0 || tmp_f[0] > 255 || tmp_f[1] < 0 || tmp_f[1] > 255 || tmp_f[2] < 0 || tmp_f[2] > 255)) || \
        (tmp_c[0] < 0 || tmp_c[0] > 255 || tmp_c[1] < 0 || tmp_c[1] > 255 || tmp_c[2] < 0 || tmp_c[2] > 255)))
    {
        free(tmp_f);
        free(tmp_c);
        return (0);
    }
    return (1);
}
int	check_wall_textures(char **txt)
{
	size_t	i;
	size_t	j;
	int		flags;

	i = 0;
	flags = 0;
	while (txt[i])
	{
		j = 0;
		while (txt[i][j] == ' ')
			j++;
		if (ft_strncmp(txt[i] + j, "NO", 2) == 0)
		{
			if (flags & 1)
				return (0);
			flags |= 1;
		}
		else if (ft_strncmp(txt[i] + j, "SO", 2) == 0)
		{
			if (flags & 2)
				return (0);
			flags |= 2;
		}
		else if (ft_strncmp(txt[i] + j, "WE", 2) == 0)
		{
			if (flags & 4)
				return (0);
			flags |= 4;
		}
		else if (ft_strncmp(txt[i] + j, "EA", 2) == 0)
		{
			if (flags & 8)
				return (0);
			flags |= 8;
		}
		i++;
	}
	return (flags == 15);
}
