# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: overetou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 12:25:00 by overetou          #+#    #+#              #
#    Updated: 2018/02/22 19:42:11 by overetou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEI = checker

NAMEII = push_swap

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB = libft/libft.a

SRC = src/operations.c src/manager.c src/utils.c src/checker.c src/push_swap.c src/pivot.c src/sub_pivot.c \
	  src/quick_tools.c

OBJ = manager.o operations.o utils.o sub_pivot.o

CHEK = checker.o

PUSH = push_swap.o pivot.o quick_tools.o

.PHONY: all, clean, fclean, re

all: $(NAME)
	#make -C libft/
	$(CC) $(CFLAGS) -c $(SRC) -I inc/
	$(CC) $(CFLAGS) $(CHEK) $(OBJ) $(LIB) -o $(NAMEI)
	$(CC) $(CFLAGS) $(PUSH) $(OBJ) $(LIB) -o $(NAMEII)

clean:
	rm -f $(OBJ) $(CHEK) $(PUSH)
	make -C libft/ clean

fclean: clean
	rm -f $(NAMEI) $(NAMEII)
	make -C libft/ fclean

re: fclean all
