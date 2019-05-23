# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 17:43:57 by plaurent          #+#    #+#              #
#    Updated: 2019/05/23 13:50:03 by plaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = plaurent.filler

LIB = libft/libft.a

SRC = get_map.c free.c get_piece.c create_heat_map.c get_player.c filler.c	\
	find_place.c

HEADER = filler.h

OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -I $(HEADER) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

.PHONY: clean fclean

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all