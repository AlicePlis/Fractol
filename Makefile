#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsonja <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 14:12:39 by jsonja            #+#    #+#              #
#    Updated: 2020/02/13 13:24:47 by jsonja           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(shell uname), Darwin)
    LIBMLX_PATH = ./minilibx_macos/
    FRAME = -framework OpenGL -framework AppKit
endif
ifeq ($(shell uname), Linux)
     LIBMLX_PATH = ./minilibx/
     FRAME = -lX11 -lXext -lm
endif
NAME = fractol

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIB_PATH = ./libft/


SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I , $(INC_PATH))
HEADERS = $(addprefix $(INC_PATH), $(INC_NAME))
LIBFT = $(LIB_PATH)libft.a
LIBMLX = $(LIBMLX_PATH)libmlx.a
FLAGS = -Wall -Wextra -Werror
SRC_NAME = main.c	\
		    init.c \
		    color.c \
		    fractol.c \
		    mouse.c \
		    keyboard.c \
		    menu.c \
		    fractol2.c \
		    mouse_gr.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fractol.h

all: libft_update $(NAME)

libft_update: mlx_update
		make -C $(LIB_PATH)

mlx_update:
		make -C $(LIBMLX_PATH)

os:
		echo $(OS_NAME)

$(NAME): $(OBJ) $(LIBFT)
		gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(FRAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
		mkdir -p $(OBJ_PATH)
		gcc $(FLAGS) $(INC) -o $@ -c $<

clean:
		rm -rf $(OBJ_PATH)
		make clean -C $(LIB_PATH)
		make clean -C $(LIBMLX_PATH)

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIB_PATH)

re: fclean all