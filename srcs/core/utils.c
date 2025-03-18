/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:05:28 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 01:49:05 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

double	get_delta_time(void)
{
	static struct timeval	last_time = {0};
	struct timeval			current_time;
	double					delta_time;

	gettimeofday(&current_time, NULL);
	if (last_time.tv_sec == 0 && last_time.tv_usec == 0)
	{
		last_time = current_time;
		return (0.0);
	}
	delta_time = (current_time.tv_sec - last_time.tv_sec) +
				(current_time.tv_usec - last_time.tv_usec) / 1000000.0;
	last_time = current_time;
	return (delta_time);
}

char	*join_n_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dst;

	if (!s1)
	{
		if (!*s2)
			return (NULL);
		s1 = ft_substr("", 0, 1);
	}
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	j = -1;
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	free(s1);
	return (dst);
}

int	detect_map_start(t_config *config)
{
	if (!config->no_set || !config->so_set
		|| !config->we_set || !config->ea_set
		|| !config->f_set || !config->c_set)
			return (0);
	config->map_started = 1;
	return (1);
}
