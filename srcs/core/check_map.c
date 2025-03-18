# include "core_internal.h"

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
	{
		return (1);
	}
	if (check_wall(cub))
	{
		return (1);
	}
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
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	if (count_char(cub->map.col, 'N') + count_char(cub->map.col, 'W') + count_char(cub->map.col, 'E') + count_char(cub->map.col, 'S') != 1)
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
			if (i == 0 || i == cub->map.height - 1 ||
				j == 0 || j == cub->map.width - 1)
			{
				if (cub->map.col[i][j] != '1' && cub->map.col[i][j] != ' ')
					return (printf("i = %d, j = %d\n", i, j));
			}
			else if (cub->map.col[i][j] != '1' && cub->map.col[i][j] != ' ')
			{
				if (is_empty(cub->map.col[i + 1][j]) || is_empty(cub->map.col[i][j + 1]) ||
					is_empty(cub->map.col[i - 1][j]) || is_empty(cub->map.col[i][j - 1]))
					return (printf("i = %d, j = %d\n", i, j));
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	count_char(char **map, char c)
{
	int num;
	int i;
	int j;

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
