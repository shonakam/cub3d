/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 03:58:30 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 05:09:33 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putchar_fd(const char c, int fd)
{
	return (write(fd, &c, 1));
}

// #include <fcntl.h>

// int main(void)
// {
// 	char character = 'A';
// 	int fd = -1;

// 	ft_putchar_fd(character, fd);

// 	return 0;
// }