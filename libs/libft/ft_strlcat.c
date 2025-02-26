/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 02:17:54 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 02:21:25 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (!dest && dstsize <= 0)
		return (s_len);
	if (dstsize <= d_len)
		return (dstsize + s_len);
	i = 0;
	while (d_len + i < dstsize - 1 && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}

// int main() {
// 	char *dst1 = calloc(100, sizeof(char));
// 	char *dst2 = calloc(100, sizeof(char));
// 	char *src1 = calloc(100, sizeof(char));
// 	char *src2 = calloc(100, sizeof(char));
// 	for (int i = 0; i < 99; i++)
// 	{
// 		src1[i] = i + 1;
// 		src2[i] = i + 1;
// 	}

//     size_t result1 = strlcat(dst1, src1, 100);
// 	size_t result2 = ft_strlcat(dst2, src2, 100);

//     printf("Concatenated string: '%s'\n", dst1);
//     printf("Length of concatenated string: %zu\n", result1);
// 	printf("///////////////////////////////////////\n");
// 	printf("Concatenated string: '%s'\n", dst2);
//     printf("Length of concatenated string: %zu\n", result2);

// 	free(dst1);
// 	free(dst2);
// 	free(src1);
// 	free(src2);
// }
