# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 02:57:52 by min-cho           #+#    #+#              #
#    Updated: 2022/08/02 02:57:52 by min-cho          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

FILES = ft_bzero.c \
	ft_print_char.c \
	ft_print_low_base16.c \
	ft_print_nbr.c \
	ft_print_pointer.c \
	ft_print_string.c \
	ft_print_unbr.c \
	ft_print_up_base16.c \
	ft_printf.c \
	ft_strlen.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJS = ${FILES:.c=.o}

$(NAME): $(OBJS)
	ar -rcs $@ $^

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
