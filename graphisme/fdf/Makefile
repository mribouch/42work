# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 12:52:28 by mribouch          #+#    #+#              #
#    Updated: 2019/04/11 20:11:36 by mribouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c		\
	   read.c		\
	   get.c		\
	   bresenham.c	\
	   tools.c		\
	   split.c		\
	   key.c		\
	   color.c		\
	   draw.c		\
	   view.c		\
	   rot.c		\
	   free.c		\
	   matrice.c	\
	   readtools.c	\
	   parse.c		\
	   menu.c

FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
MLX = minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX) fdf.h
	gcc $(FLAGS) $(MLX) $(LIBFT) $(OBJS) \
	-framework OpenGL -framework Appkit -o fdf

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx_macos

clean:
	rm -rf $(OBJS)
	make clean -C libft/

fclean: clean
	rm -rf fdf libft/libft.a minilibx_macos/libmlx.a

re: fclean $(NAME)