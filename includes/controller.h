/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:21:46 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/08 09:13:09 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# ifdef __APPLE__
# define KEY_ESC 65307
# define KEY_W   119
# define KEY_A   97
# define KEY_S   115
# define KEY_D   100
# define KEY_LEFT 65361
# define KEY_UP   65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# elif __linux__
# include <X11/keysym.h>
# define KEY_ESC XK_Escape
# define KEY_W   XK_w
# define KEY_A   XK_a
# define KEY_S   XK_s
# define KEY_D   XK_d
# define KEY_LEFT XK_Left
# define KEY_RIGHT XK_Right
# define KEY_UP   XK_Up
# define KEY_DOWN XK_Down

# endif

#endif /* CONTROLLER_H */
