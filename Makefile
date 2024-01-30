# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 17:02:01 by achraiti          #+#    #+#              #
#    Updated: 2024/01/29 16:42:41 by achraiti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME2 = checker

SRC = pushswap.c checkers.c rule1.c rule2.c rule3.c algo.c algo2.c algo3.c

SRC2 = checker.c rule01.c rule02.c rule03.c checkers.c checker_utils.c checker_utils2.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && $(MAKE)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)
	
bonus: $(NAME2)

$(NAME2): $(OBJ2)
	cd libft && $(MAKE)
	$(CC) $(CFLAGS) $(OBJ2) $(INCLUDES) -o $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf libft/*.o
	rm -rf $(OBJ)
	rm -rf $(OBJ2)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)
	rm -rf $(NAME2)

re: fclean all

.PHONY: clean re all fclean bonus