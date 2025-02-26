/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:15:51 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 04:23:32 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

void		set_hex_digits(char format, char *hex_digits);
ssize_t		safe_putstr(const char *s, int fd);
ssize_t		safe_putchar(char c, int fd);
ssize_t		ft_put_unsigned_nbr(unsigned int n, int fd);
ssize_t		ft_puthex(unsigned int num, char format, int fd);
ssize_t		ft_putptr_fd(uintptr_t ptr, int fd);
int			ft_printf(const char *format, ...)
			__attribute__((format(printf, 1, 2)));
#endif