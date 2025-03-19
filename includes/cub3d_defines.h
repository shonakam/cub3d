/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_defines.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 02:36:44 by shonakam          #+#    #+#             */
/*   Updated: 2025/03/19 11:15:45 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINES_H
# define CUB3D_DEFINES_H

# define WINDOW_WIDTH  800
# define WINDOW_HEIGHT 600

/* per second */
# define RADIUS 0.2
# define BASE_MOVE_SPEED 2.0
# define BASE_ROT_SPEED 90.0

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

# define ERROR_INVALID_FILE       "Error: Invalid .cub file format."
# define ERROR_INVALID_IDENTIFIER "Error: Unknown identifier in .cub file."
# define ERROR_INVALID_RGB        "Error: Invalid RGB color values. Must be in range 0-255."
# define ERROR_MALLOC "Error: Memory allocation failed."

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

#define MAP_MAX_WIDTH 150
#define MAP_MAX_HEIGHT 100

#endif /* CUB3D_DEFINES_H */
