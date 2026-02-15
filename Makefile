# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tokyrand <tokyrand@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/15 13:05:26 by tokyrand          #+#    #+#              #
#    Updated: 2026/02/15 16:52:55 by tokyrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_print_ptr.c\
	  ft_print_str.c\
	  ft_print_u.c\
	  ft_printf.c\
	  ft_putnbr.c\
	  ft_utils.c\
	  ft_strlcpy.c

OBJ = $(SRC:.c=.o)
HEADERS = ft_printf.h
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	ar -rcs $@ $^

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re