/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:36:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/02/23 02:41:32 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

# define WINDOW_WIDTH  800
# define WINDOW_HEIGHT 600
# define PLAYER_SPEED 0.1
# define ROTATION_SPEED 0.05

# define TEXTURE_NORTH "NO"
# define TEXTURE_SOUTH "SO"
# define TEXTURE_WEST "WE"
# define TEXTURE_EAST "EA"

# define COLOR_FLOOR "F"
# define COLOR_CEILING "C"

# define COLOR_MIN 0
# define COLOR_MAX 255

# define MAP_WALL '1'
# define MAP_FLOOR '0'
# define MAP_PLAYER_NORTH 'N'
# define MAP_PLAYER_SOUTH 'S'
# define MAP_PLAYER_WEST 'W'
# define MAP_PLAYER_EAST 'E'

# define ERROR_INVALID_FILE       "Error: Invalid .cub file format.\n"
# define ERROR_INVALID_IDENTIFIER "Error: Unknown identifier in .cub file.\n"
# define ERROR_INVALID_RGB        "Error: Invalid RGB color values. Must be in range 0-255.\n"

#endif /* CUB3D_DEFINES_H */
