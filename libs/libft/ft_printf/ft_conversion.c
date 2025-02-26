/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:40:53 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 04:28:46 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putptr_fd(uintptr_t ptr, int fd)
{
	char	*hex_digits = "0123456789abcdef";
	char	buffer[20];
	size_t	i;
	ssize_t	count, result;

	i = 0;
	count = 0;
	if (!ptr)
		return (safe_putstr("0x0", fd));
	while (ptr)
	{
		buffer[i++] = hex_digits[ptr % 16];
		ptr /= 16;
	}
	if ((result = safe_putstr("0x", fd)) < 0)
		return (-1);
	count += result;
	while (i--)
	{
		if ((result = safe_putchar(buffer[i], fd)) < 0)
			return (-1);
		count += result;
	}
	return (count);
}

/* */
ssize_t	ft_puthex(unsigned int num, char format, int fd)
{
	char	hex_digits[17];
	char	buff[10];
	ssize_t	count;
	ssize_t	result;
	size_t	i;

	set_hex_digits(format, hex_digits);
	i = 0;
	count = 0;
	if (num == 0)
		return (safe_putchar('0', fd));
	while (num)
	{
		buff[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (i--)
	{
		if ((result = safe_putchar(buff[i], fd)) < 0)
			return (-1);
		count += result;
	}
	return (count);
}

ssize_t	ft_put_unsigned_nbr(unsigned int n, int fd)
{
	ssize_t	count, result;

	count = 0;
	if (n >= 10)
	{
		if ((result = ft_put_unsigned_nbr(n / 10, fd)) < 0)
			return (-1);
		count += result;
	}
	if ((result = safe_putchar((n % 10) + '0', fd)) < 0)
		return (-1);
	count += result;
	return (count);
}
