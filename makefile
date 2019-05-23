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

all = $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC) -o $(NAME) -I $(HEADER)

%.o: %.c
	@$(CC) -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
