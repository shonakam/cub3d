/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:28 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 03:19:29 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cast_c;

	cast_c = (unsigned char)c;
	while (*s)
	{
		if (*s == cast_c)
			return ((char *)s);
		s++;
	}
	if (cast_c == '\0')
		return ((char *)s);
	return (NULL);
}
