/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:19:47 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/13 21:35:21 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_and_update_save(char **save)
{
	char	*line;
	char	*new_save;
	size_t	len;

	if (!*save)
		return (NULL);
	len = ft_strlenx(*save, '\n');
	line = ft_strndup(*save, len + 1);
	if ((*save)[len] == '\n')
	{
		new_save = ft_strndup(*save + len + 1, ft_strlenx(*save, '\0') - len);
		if (!new_save)
			return (NULL);
		ft_free(save);
		*save = new_save;
	}
	else
	{
		ft_free(save);
		*save = NULL;
	}
	return (line);
}

static char	*ft_join_free(char *save, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(save, buf);
	ft_free(&save);
	return (tmp);
}

static ssize_t	read_and_fill(int fd, char **buf, char **save)
{
	ssize_t	read_c;

	read_c = read(fd, *buf, BUFFER_SIZE);
	if (read_c < 0)
		return (-1);
	(*buf)[read_c] = '\0';
	if (*save)
		*save = ft_join_free(*save, *buf);
	else
		*save = ft_strndup(*buf, ft_strlenx(*buf, '\0'));
	return (read_c);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*save;
	ssize_t		read_c;

	if (fd < 0 || fd > OPEN_MAX - _SC_OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (ft_free(&buf), NULL);
	while (!save || !ft_strchr(save, '\n'))
	{
		read_c = read_and_fill(fd, &buf, &save);
		if (read_c <= 0)
			break ;
	}
	ft_free(&buf);
	if (read_c <= 0 && (!save || !*save))
	{
		if (save)
			ft_free(&save);
		return (NULL);
	}
	return (get_line_and_update_save(&save));
}

// int main()
// {
// 		int fd = open("test", O_RDONLY);
// 		int i = 0;
// 		char *line;

// 		while (1)
// 		{
// 			line = get_next_line(fd);
// 			printf("[%d]	%s", i++, line);
// 			if (line == NULL)
// 				break ;
// 			free(line);
// 		}
// 		close(fd);
// }
