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
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c

FILSE2 = ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstmap.c \

OBJS = ${FILES:.c=.o}
OBJS2 = ${FILES2:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCS = includes

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

bonus : $(OBJS2)
	ar -rcs $(NAME) $^

clean:
	rm -f $(OBJS) $(OBJS2)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all bonus clean fclean re

# r : 새로운 옵젝파일이면 추가,기존 파일이면 치환
# c : 아카이브(라이브러리파일)생성, 또는 갱신하는경우에도 경고메세지 출력 xx
# s : 아카이브 인덱스 생성 < 안할경우 링크 속도가 느려지고 환경에따라 에러발생