# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 12:52:23 by tokyrand          #+#    #+#              #
#    Updated: 2026/02/11 14:08:02 by tokyrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_count.c\
	  ft_printf.c\
	  ft_putchar.c\
	  ft_putnbr_base.c\
	  ft_putnbr.c\
	  ft_putstr.c\
	  libft/ft*.c

OBJ = $(SRC:.c=.o)
HEADERS = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	ar -rcs $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY:	all clean fclean re