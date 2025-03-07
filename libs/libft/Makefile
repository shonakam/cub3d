# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:35:50 by shonakam          #+#    #+#              #
#    Updated: 2025/03/06 03:42:49 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC ?= cc
CFLAGS  := -Wall -Wextra -Werror

OBJS_DIR := objs
SRCS := $(shell find . -type f | grep '\.c$$')
OBJS := $(SRCS:%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
