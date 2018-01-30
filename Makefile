# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: overetou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 12:25:00 by overetou          #+#    #+#              #
#    Updated: 2018/01/29 18:25:40 by overetou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

CC = gcc

SCHKR = main.c

SPS = main.c

.PHONY: all, clean, fclean, re

all: $(NAME)
	S(CC) -C libft/ make

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
