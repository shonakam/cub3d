/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:29:09 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/05 02:58:19 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	validate_extension(const char *file)
{
	const char	*ext;

	if (!file)
		return (0);
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".cub", 5) != 0)
		return (0);
	return (1);
}
