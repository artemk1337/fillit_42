# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 10:57:48 by jkimberl          #+#    #+#              #
#    Updated: 2019/09/19 16:37:00 by jkimberl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_abs.c ft_strncmp.c ft_atoi.c ft_memalloc.c ft_strcat.c ft_strncpy.c ft_bzero.c ft_memccpy.c ft_strchr.c ft_strnequ.c ft_isalnum.c ft_memchr.c ft_strclr.c ft_strnew.c ft_isalpha.c ft_memcmp.c ft_strcmp.c ft_strnstr.c ft_isascii.c ft_memcpy.c ft_strcpy.c ft_strrchr.c ft_isdigit.c ft_memdel.c ft_strdel.c ft_strsplit.c ft_isprint.c ft_memmove.c ft_strdup.c ft_strstr.c ft_itoa.c ft_memset.c ft_strequ.c ft_strsub.c ft_putchar.c ft_striter.c ft_strtrim.c ft_putchar_fd.c ft_striteri.c ft_tolower.c ft_putendl.c ft_strjoin.c ft_toupper.c ft_putendl_fd.c ft_strlcat.c ft_putnbr.c ft_strlen.c ft_putnbr_fd.c ft_strmap.c ft_putstr.c ft_strmapi.c ft_putstr_fd.c ft_strncat.c ft_skipwhitespaces.c


O_FILES = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

all: $(NAME)

$(NAME): $(SRCS) $(O_FILES) $(HEADER)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

$(O_FILES): %.o: %.c
	    gcc -c $(CFLAGS) $< -I$(HEADER)

clean:
	rm -rf $(O_FILES)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
