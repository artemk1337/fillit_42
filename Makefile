# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchadwic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 17:08:29 by cchadwic          #+#    #+#              #
#    Updated: 2019/09/23 17:22:52 by jkimberl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= ./src/adds.c \
		  ./src/change_input.c \
		  ./src/ft_find_solution.c \
		  ./src/ft_find_solution_extra.c \
		  ./src/main.c \
		  ./src/is_valid.c \
		  ./src/array_operations.c

OBJ		= $(SRC:.c=.o)

INCLUDE = ./includes

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ) $(INCLUDE)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(INCLUDE) ./libft/libft.a

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all
