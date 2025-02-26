/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:50:38 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 04:54:19 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*s_dst;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	size = end - start;
	s_dst = (char *)malloc(size + 1);
	if (!s_dst)
		return (NULL);
	ft_strlcpy(s_dst, s1 + start, size + 1);
	return (s_dst);
}

// int main()
// {
// 	char	*val;
// 	val = ft_strtrim("aaaaaaaaa", "a");
// 	printf("'%s'\n", val);
// }
