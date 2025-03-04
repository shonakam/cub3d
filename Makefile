# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 00:08:31 by shonakam          #+#    #+#              #
#    Updated: 2025/03/05 00:57:24 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC ?= cc
# CFLAGS := -Wall -Werror -Wextra
X11_FLAGS := $(shell pkg-config --cflags --libs x11 xext)

ifeq ($(shell uname), Darwin)
	MLX := libs/minilibx/libmlx_Darwin.a
	MLX_FLAGS := -Llibs/minilibx -lmlx -framework OpenGL -framework AppKit
else
	MLX := libs/minilibx/libmlx_Linux.a
	MLX_FLAGS := -Llibs/minilibx -lmlx -lX11 -lXext -lm
endif

SRCS := $(shell find srcs -type f)

all: $(NAME)

test:
	@echo "OS: $(UNAME)"
	@echo "MLX_FLAGS: $(MLX_FLAGS)"
	@echo "X11_FLAGS: $(X11_FLAGS)"
	@echo "Sources: $(SRCS)"

$(NAME):
	@$(MAKE) -C libs/libft
	@$(MAKE) -C libs/minilibx
	@CC $(CFLAGS) $(SRCS) -o $(NAME) $(MLX_FLAGS) $(X11_FLAGS)

clean:
	@$(MAKE) -C libs/minilibx clean
	@$(MAKE) -C libs/libft clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) -C libs/minilibx clean
	@$(MAKE) -C libs/libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
