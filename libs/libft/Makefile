# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:35:50 by shonakam          #+#    #+#              #
#    Updated: 2025/03/08 10:17:25 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC ?= cc
CFLAGS  := -Wall -Wextra -Werror

OBJS_DIR := objs
SRCS := $(shell find . -type f | grep '\.c$$')
OBJS := $(SRCS:%.c=objs/%.o)

GREEN  := \033[0;32m
YELLOW := \033[0;33m
RED    := \033[0;31m
RESET  := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)[SUCCESS]: Library created -> $(NAME)$(RESET)"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)[CLEAN]: Removed object files$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[FCLEAN]: Removed $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re
