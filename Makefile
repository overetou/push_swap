# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: overetou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 12:25:00 by overetou          #+#    #+#              #
#    Updated: 2018/01/31 15:19:14 by overetou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEI = checker

NAMEII = push_swap

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB = libft/libft.a

SRC = src/operations. src/manager.c src/utils.c src/checker.c src/push_swap.c

OBJ = src/manager.o src/operations.o src/utils.o

CHEK = src/checker.o

PUSH = src/push_swap.o

.PHONY: all, clean, fclean, re

all: $(NAME)
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(CHEK) $(OBJ) $(LIB) -I inc/ -o $(NAMEI)
	$(CC) $(CFLAGS) $(PUSH) $(OBJ) $(LIB) -I inc/ -o $(NAMEII)

clean:
	rm -f $(OBJ) $(CHEK) $(PUSH)
	make -C libft/ clean

fclean: clean
	rm -f $(NAMEI) $(NAMEII)
	make -C libft/ fclean

re: fclean $(NAME)
