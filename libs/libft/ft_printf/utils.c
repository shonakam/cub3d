/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 04:13:46 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 04:30:42 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* hex_digits[17] is stack-allocated, ensuring ft_strlcpy() works safely.　*/
void	set_hex_digits(char format, char *hex_digits)
{
	if (format == 'x')
		ft_strlcpy(hex_digits, "0123456789abcdef", 17);
	else
		ft_strlcpy(hex_digits, "0123456789ABCDEF", 17);
}

ssize_t	safe_putstr(const char *s, int fd)
{
	ssize_t	result;

	result = ft_putstr_fd(s, fd);
	if (result < 0)
		return (-1);
	return (result);
}

ssize_t	safe_putchar(char c, int fd)
{
	ssize_t	result;

	result = ft_putchar_fd(c, fd);
	if (result < 0)
		return (-1);
	return (result);
}
