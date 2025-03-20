/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:00:06 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/20 15:02:57 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_rm_newline(char *line)
{
	size_t	i;

	if (!line)
		return ;
	i = ft_strlen(line);
	if (line[i - 1] == '\n')
		line[i - 1] = '\0';
}
