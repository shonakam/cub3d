#include "../includes/cub3d.h"

int is_condition(char **map)
{
    if (map == NULL)
        return (0);
	if (has_one_player(map)	!= 1)
		return (0);
	if (surround_wall(map) == 0)
		return (0);
	if (prohibited_c(map) == 0)
		return (0);
    return (1);
}

int has_one_player(char **map)
{
	size_t	i;
	int		signal;

	signal = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'N') || ft_strchr(map[i], 'S') || ft_strchr(map[i], 'W') || ft_strchr(map[i], 'E'))
			signal++;
		i++;
	}
	if (signal == 1)
		return (1);
	else if (signal > 1)
		return (printf("Error\nThere are more than one player\n"), 2);
	else
		return (printf("Error\nThere is no player\n"), 0);
}

int surround_wall(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		if (map[i] == '0')
			return (0);
		i++;
	}
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i + 1][j])
		{
			if (map[i][j] == '0' && map[i][j + 1] == ' ')
				return (0);
			if (map[i][j] == '0' && map[i][j - 1] == ' ')
				return (0);
			if (map[i][j] == '0' && map[i + 1][j] == ' ')
				return (0);
			if (map[i][j] == '0' && map[i - 1][j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	while (map[i][j])
	{
		if (map[i][j] == '0')
			return (0);
		j++;
	}
	return (1);
}

int prohibited_c(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j =	0;
		while (map[i][j])
		{
			if (map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != 'S' map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}