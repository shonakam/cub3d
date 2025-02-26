/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 04:34:45 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 05:09:27 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putendl_fd(const char *s, int fd)
{
	ssize_t	result;
	ssize_t	count;

	if (!s)
		return (-1);
	count = ft_putstr_fd(s, fd);
	if (count < 0)
		return (-1);
	result = ft_putchar_fd('\n', fd);
	if (result < 0)
		return (-1);
	return (count + result);
}

// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		int	fd = 1;
// 		char *input = av[1];
// 		printf("%s\n", input);
// 		ft_putendl_fd(input, fd);
// 	}
// }