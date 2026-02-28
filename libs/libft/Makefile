# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 19:24:59 by xviladri          #+#    #+#              #
#    Updated: 2024/10/15 20:29:31 by xviladri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
                                ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
                                ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
                                ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
                                ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
                                ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
                                ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
                                ft_printf.c ft_printf_utils.c
OBJS = $(SRC:.c=.o)

BONUS_SRCS = ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

# Bonus Object files
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = libft.a
HEADER = libft.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rsc
all: $(NAME)

# Create the static library
ifndef BONUS
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
else
$(NAME): $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
endif

bonus: 
	@make BONUS=42 --no-print-directory

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) .bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
