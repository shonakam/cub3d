/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:19:40 by mfukui            #+#    #+#             */
/*   Updated: 2023/10/11 23:58:00 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **p)
{
	if (*p)
		free(*p);
	*p = NULL;
}

size_t	ft_strlenx(const char *str, char signal)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != signal)
		i++;
	return (i);
}

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	char	*result;
// 	size_t	dst_len;
// 	size_t	src_len;
// 	size_t	i;
// 	size_t	j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	dst_len = ft_strlenx(s1, '\0');
// 	src_len = ft_strlenx(s2, '\0');
// 	result = (char *)malloc(dst_len + src_len + 1);
// 	if (!result)
// 		return (NULL);
// 	i = 0;
// 	while (i < dst_len)
// 	{
// 		result[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (j < src_len)
// 		result[i++] = s2[j++];
// 	result[i] = '\0';
// 	return (result);
// }

char	*ft_strndup(const char *src, size_t nb)
{
	size_t	len;
	char	*dest;

	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	dest = (char *)malloc(nb + 1);
	if (!dest)
		return (NULL);
	len = 0;
	while (src[len] && len < nb)
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	if (!s)
// 		return (NULL);
// 	while (*s)
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (c == 0)
// 		return ((char *)s);
// 	return (NULL);
// }
