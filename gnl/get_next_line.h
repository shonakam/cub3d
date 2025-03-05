/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:19:50 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/11 23:58:29 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
// char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strndup(const char *src, size_t nb);
// char	*ft_strchr(const char *s, int c);
size_t	ft_strlenx(const char *str, char signal);
void	ft_free(char **p);

#endif