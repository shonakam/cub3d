/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:36:27 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/27 04:45:48 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	return ((int)ft_atoll(s));
}
// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		int	res1 = ft_atoi(av[1]);
// 		int	res2 = atoi(av[1]);
// 		printf("ft :'%d'\n", res1);
// 		printf("uni:'%d'\n", res2);
// 	}
// }
