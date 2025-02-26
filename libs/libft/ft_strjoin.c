/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:58:52 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 04:49:21 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str_dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str_dest == NULL)
		return (NULL);
	ft_strlcpy(str_dest, s1, s1_len + 1);
	ft_strlcat(str_dest, s2, s1_len + s2_len + 1);
	return (str_dest);
}

// int main()
// {
//     // テストケース1: 2つの文字列を連結する
//     const char *s1 = "Hello, ";
//     const char *s2 = "world!";
//     char *result1 = ft_strjoin(s1, s2);
//     if (result1 != NULL)
//     {
//         printf("Test case 1: %s\n", result1);
//         free(result1); // メモリ解放
//     }
//     else
//     {
//         printf("Test case 1: Memory allocation failed\n");
//     }

//     // テストケース2: 1つ目の文字列が空の場合
//     const char *s3 = "";
//     char *result2 = ft_strjoin(s3, s2);
//     if (result2 != NULL)
//     {
//         printf("Test case 2: %s\n", result2);
//         free(result2);
//     }
//     else
//     {
//         printf("Test case 2: Memory allocation failed\n");
//     }

//     // テストケース3: 2つ目の文字列が空の場合
//     const char *s4 = "Hello, ";
//     const char *s5 = "";
//     char *result3 = ft_strjoin(s4, s5);
//     if (result3 != NULL)
//     {
//         printf("Test case 3: %s\n", result3);
//         free(result3);
//     }
//     else
//     {
//         printf("Test case 3: Memory allocation failed\n");
//     }

//     // テストケース4: 両方の文字列が空の場合
//     const char *s6 = "";
//     const char *s7 = "";
//     char *result4 = ft_strjoin(s6, s7);
//     if (result4 != NULL)
//     {
//         printf("Test case 4: %s\n", result4);
//         free(result4);
//     }
//     else
//     {
//         printf("Test case 4: Memory allocation failed\n");
//     }

// 	// テストケース4: 両方の文字列が空の場合
//     const char *s8 = NULL;
//     const char *s9 = NULL;
//     char *result5 = ft_strjoin(s8, s9);
//     if (result5 == NULL)
//     {
//         printf("Test case 5: %s\n", result5);
//         free(result5);
//     }
//     else
//     {
//         printf("Test case 5: Memory allocation failed\n");
//     }
// }
