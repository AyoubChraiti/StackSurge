# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:02:01 by achraiti          #+#    #+#              #
#    Updated: 2024/01/18 12:14:07 by achraiti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = pushswap.c checkers.c rule1.c rule2.c rule3.c algo.c algo2.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && $(MAKE)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf libft/*.o
	rm -rf $(OBJ)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: clean re all fclean