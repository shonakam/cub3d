/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:57:16 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 04:14:53 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	handle_conversion(va_list ap, char specifier)
{
	ssize_t	result;

	if (specifier == 'c')
		result = ft_putchar_fd(va_arg(ap, int), 1);
	else if (specifier == 's')
		result = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (specifier == 'd' || specifier == 'i')
		result = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (specifier == 'u')
		result = ft_put_unsigned_nbr(va_arg(ap, unsigned int), 1);
	else if (specifier == 'x' || specifier == 'X')
		result = ft_puthex(va_arg(ap, unsigned int), specifier, 1);
	else if (specifier == 'p')
		result = ft_putptr_fd((uintptr_t)va_arg(ap, void *), 1);
	else if (specifier == '%')
		result = ft_putchar_fd('%', 1);
	else
		return (-1);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	count;
	ssize_t	result;
	size_t	i;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			result = handle_conversion(ap, format[++i]);
		else
			result = ft_putchar_fd(format[i], 1);
		if (result < 0)
			return (va_end(ap), -1);
		count += result;
		i++;
	}
	va_end(ap);
	return (count);
}
