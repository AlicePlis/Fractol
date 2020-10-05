#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsonja <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 14:12:39 by jsonja            #+#    #+#              #
#    Updated: 2019/10/15 15:35:55 by jsonja           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRCS = ft_wcount.c ft_isascii.c ft_memcpy.c ft_strcpy.c ft_strncpy.c ft_isdigit.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isprint.c ft_memset.c ft_strlcat.c ft_strrchr.c ft_bzero.c ft_memccpy.c ft_strcat.c ft_strlen.c ft_strstr.c ft_isalnum.c ft_memchr.c ft_strchr.c ft_strncat.c ft_tolower.c ft_isalpha.c ft_memcmp.c ft_strcmp.c ft_strncmp.c ft_toupper.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_atoi.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_strsplit.c ft_itoa.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isspace.c ft_nbrlen.c ft_isupper.c ft_islower.c ft_swap.c get_next_line.c ft_exit.c ft_atoi_base.c ft_absf.c ft_maxf.c ft_wcount.c
RES = $(SRCS:.c=.o)
HEADER = libft.h
INCLUDES = -I ./
all: $(NAME)
$(NAME): $(RES) $(HEADER)
		ar -rsc $(NAME) $(RES)
%.o: %.c
		gcc -Wall -Wextra -Werror $(INCLUDES) -o $@ -c $<
clean:
		rm -f $(RES)
fclean: clean
		rm -f $(NAME)
re: fclean all
