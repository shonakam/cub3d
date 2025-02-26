/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 02:42:22 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 03:48:45 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s == NULL)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/////////////////////////////////////////////////////////////

// char	ft_test_toupper(unsigned int index, char c)
// {
// 	(void)index;

// 	if ('a' <= c && c <= 'z')
// 		return (c - 'a' + 'A');
// 	return (c);
// }

// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		char *input = av[1];
// 		char *output = ft_strmapi(input, ft_test_toupper);
// 		if (output != NULL)
// 		{
// 			printf("Original: %s\n", input);
// 			printf("Transformed: %s\n", output);
// 			free(output);
// 		}
// 		else
// 		{
// 			printf("Memory allocation failed.\n");
// 		}
// 	}
// }
