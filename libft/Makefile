# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 23:05:03 by min-cho           #+#    #+#              #
#    Updated: 2022/01/23 23:05:03 by min-cho          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c
OBJS = ${FILES:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCS = includes

$(NAME): $(OBJS)
			ar -rcs $(NAME) $(OBJS)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
