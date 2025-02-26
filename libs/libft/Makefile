# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:35:50 by shonakam          #+#    #+#              #
#    Updated: 2025/02/27 05:35:01 by shonakam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC ?= cc
CFLAGS  := -Wall -Wextra -Werror

SRCS := ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
        ft_isdigit ft_isprint ft_memchr ft_memcmp ft_memcpy ft_memmove \
        ft_memset ft_strchr ft_strlen ft_strlcpy ft_strlcat ft_strrchr \
        ft_strnstr ft_strncmp ft_toupper ft_tolower ft_strdup ft_substr \
        ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
        ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
        ft_atoll ft_is_whitespace ft_is_plus_minus ft_is_digit \
\
        ft_printf/ft_printf ft_printf/ft_conversion ft_printf/utils \
        get_next_line/get_next_line \

OBJS_DIR := objs
OBJS := $(SRCS:%=$(OBJS_DIR)/$(notdir %.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/ft_printf
	@mkdir -p $(OBJS_DIR)/get_next_line

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
