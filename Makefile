# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 00:08:31 by shonakam          #+#    #+#              #
#    Updated: 2025/03/05 04:57:29 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC ?= cc
# CFLAGS := -Wall -Werror -Wextra
X11_FLAGS := $(shell pkg-config --cflags --libs x11 xext)

LIBS := libs/libft/libft.a
ifeq ($(shell uname), Darwin)
	LIBS += libs/minilibx/libmlx_Darwin.a -framework OpenGL -framework AppKit
else
	LIBS += libs/minilibx/libmlx_Linux.a -lX11 -lXext -lm
endif

OBJS_DIR := objs
SRCS := $(shell find srcs -type f | grep '\.c$$')
OBJS := $(SRCS:srcs/%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libs/libft
	@$(MAKE) -C libs/minilibx
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(X11_FLAGS) -o $(NAME) 

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C libs/minilibx clean
	@$(MAKE) -C libs/libft clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) -C libs/minilibx clean
	@$(MAKE) -C libs/libft fclean
	@rm -f $(NAME)

re: fclean all

debug:
	@CC $(CFLAGS) -g -fsanitize=address $(OBJS) $(LIBS) $(X11_FLAGS) -o $(NAME)

.PHONY: all clean fclean re
