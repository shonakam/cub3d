/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:35:28 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 21:36:04 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

int	parse_color(t_cub3d *cub, char *line)
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