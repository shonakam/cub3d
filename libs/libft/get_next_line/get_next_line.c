/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:57:21 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 03:06:12 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_strdup(stash + i + 1);
	free(stash);
	return (new_stash);
} 

/*  malloc(i + 2) for newline, +1 for '\0' */
static char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i + 2);
	return (line);
}

static char	*ft_readline(int fd, char *stash)
{
	int		byte;
	char	*buf;
	char	*tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(stash), NULL);
	byte = 1;
	while (!ft_strchr(stash, '\n') && byte != 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
			return (free(buf), free(stash), NULL);
		buf[byte] = '\0';
		tmp = ft_strjoin(stash, buf);
		if (!tmp)
			return (free(buf), free(stash), NULL);
		free(stash);
		stash = tmp;
	}
	return (free(buf), stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = ft_readline(fd, stash);
	if (!stash)
		return (free(stash), NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}
