/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:43:39 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/18 16:26:42 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_INTERNAL_H
# define CORE_INTERNAL_H

# include <sys/time.h>
# include "includes/cub3d.h"

void	setup_cub(t_cub3d *cub);
int		set_coredata(t_cub3d *cub, int fd);

#endif /* CORE_INTERNAL_H */