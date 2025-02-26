/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 04:49:27 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 05:04:24 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t len = 0;
	ssize_t written;

	if (n == -2147483648)
		return ft_putstr_fd("-2147483648", fd);
	if (n < 0)
	{
		written = ft_putchar_fd('-', fd);
		if (written == -1)
			return -1;
		len += written;
		n = -n;
	}
	if (n >= 10)
	{
		written = ft_putnbr_fd(n / 10, fd);
		if (written == -1)
			return -1;
		len += written;
	}
	written = ft_putchar_fd((n % 10) + '0', fd);
	if (written == -1)
		return -1;
	len += written;
	return (len);
}

// #include "limits.h"
// int main(int ac, char **av)
// {
// 	int	fd = 1;
// 	ft_putnbr_fd(INT_MAX, fd);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(INT_MIN, fd);
// 	write(1, "\n", 1);
// 	if (ac == 2)
// 	{
// 		char *input = av[1];
// 		int num = atoi(input);
// 		printf("%s\n", input);
// 		ft_putnbr_fd(num, fd);
// 	}
// }
