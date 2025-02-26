/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 04:24:23 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 05:09:00 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr_fd(const char *s, int fd)
{
	ssize_t	result;

	if (!s)
		return (write(fd, "(null)", 6));
	result = write(fd, s, ft_strlen(s));
	if (result < 0)
		return (-1);
	return (result);
}
