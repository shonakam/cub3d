#include "../includes/cub3d.h"

int is_con_txt(t_game *game)
{
	int	signal;

	signal = 0;
	if (game->txt == NULL)
		return (0);
	if (check_wall_textures(game->txt) == 0)
		signal++;
	if (signal == 0)
		return (1);
	return (0);
}

int	check_wall_textures(char **txt)
{
	int signal;

	signal = 0;
	if (has_one_wall_info(txt, "NO") == 1)
		signal++;
	if (has_one_wall_info(txt, "SO") == 1)
		signal++;
	if (has_one_wall_info(txt, "WE") == 1)
		signal++;
	if (has_one_wall_info(txt, "EA") == 1)
		signal++;
	if (has_one_wall_info(txt, "F") == 1)
		signal++;
	if (has_one_wall_info(txt, "C") == 1)
		signal++;
	if (signal == 6)
		return (1);
	return (0);
}

int	has_one_wall_info(char **txt, char *str)
{
	size_t i;
	int signal;

	signal = 0;
	i = 0;
	while (txt[i])
	{
		if (ft_strnstr(txt[i], str, 2))
			signal++;
		i++;
	}
	if (signal == 1)
		return (1);
	else if (signal > 1)
		return (printf("Error\nThere are more than one %s\n", str), 2);
	else
		return (printf("Error\nThere is no %s\n", str), 0);
}
