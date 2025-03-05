#include "../includes/cub3d.h"

int	is_con_map(char **map)
{
	int signal;

	signal = 0;
	if (map == NULL)
		return (0);
	if (has_one_player(map)	!= 1)
		signal++;
	if (surround_wall(map) == 0)
		signal++;
	if (prohibited_c(map) == 0)
		signal++;
	if (signal == 0)
		return (1);
	return (0);
}

int	has_one_player(char **map)
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
		return (error_print(MORE_THAN_ONE_PLAYER), 2);
	else
		return (error_print(NO_PLAYER), 0);
}

int surround_wall(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[0][j] != '1' && map[0][j] != ' ')
				return (error_print(INVALID_MAP_SURROUND), 0);
			if (map[i][j + 1] && (map[i][j] != '1' && map[i][j] != ' ') && (map[i][j + 1] == ' ' || map[i][j + 1] == '\0'))
				return (error_print(INVALID_MAP_SURROUND), 0);
			if (j > 0 && (map[i][j] != '1' && map[i][j] != ' ') && (map[i][j - 1] == ' ' || map[i][j - 1] == '\0'))
				return (error_print(INVALID_MAP_SURROUND), 0);
			if (map[i + 1] && (map[i][j] != '1' && map[i][j] != ' ')  && (map[i + 1][j] == ' ' || map[i + 1][j] == '\0'))
				return (error_print(INVALID_MAP_SURROUND), 0);
			if (i > 0 && (map[i][j] != '1' && map[i][j] != ' ') && (map[i - 1][j] == ' ' || map[i - 1][j] == '\0'))
				return (error_print(INVALID_MAP_SURROUND), 0);
			j++;
        }
		i++;
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
			if (map[i][j] != 'N' && map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != 'S' && map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
				return (error_print(INVALID_MAP_CHARACTER), 0);
			j++;
		}
		i++;
	}
	return (1);
}