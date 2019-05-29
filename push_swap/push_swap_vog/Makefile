# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviana <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 11:23:59 by eviana            #+#    #+#              #
#    Updated: 2019/04/16 11:38:33 by eviana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME_C = checker
NAME_P = push_swap

RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
PURPLE = "\033[0;35m"
CYAN = "\033[0;36m"
MAGENTA = "\033[0;35;1m"
RESET = "\033[0m"

SRC_C = checker.c pile.c tools.c moves.c moves2.c quick_sort.c close.c	\
		action.c check.c

SRC_P = push_swap.c pile.c tools.c moves.c moves2.c sorter.c values.c	\
		reorder.c rerack_cases.c rerack.c median_split.c init_sort.c	\
		activ.c quick_sort.c close.c easy_sort.c all_chunks.c check.c	\

HEADER = includes/

LIB = libft/libft.a

OBJ_C = $(SRC_C:.c=.o)

OBJ_P = $(SRC_P:.c=.o)

all:		$(NAME_C) $(NAME_P)

$(NAME_C):	$(OBJ_C)
	@make -C libft
	@$(CC) -o $(NAME_C) $(CFLAGS) $(OBJ_C) -I $(HEADER) $(LIB)
	@echo $(CYAN)*****$(GREEN)checker compiled$(CYAN)*****

$(NAME_P):	$(OBJ_P)
	@make -C libft
	@$(CC) -o $(NAME_P) $(CFLAGS) $(OBJ_P) -I $(HEADER) $(LIB)
	@echo $(CYAN)*****$(GREEN)push_swap compiled$(CYAN)*****

%.o: %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

.PHONY: clean fclean

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ_C) $(OBJ_P)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME_C) $(NAME_P)

re: fclean all
