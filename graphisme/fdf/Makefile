# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 12:52:28 by mribouch          #+#    #+#              #
#    Updated: 2019/02/13 13:58:32 by mribouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c	\
	   read.c	\
	   draw.c	\
	   get.c	\
	   move.c	\
	   scale.c	\
	   key.c

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	make -C minilibx_macos/
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) minilibx_macos/libmlx.a libft/libft.a $(OBJS) \
	-framework OpenGL -framework Appkit -o fdf

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf fdf libft/libft.a minilibx_macos/libmlx.a

re: fclean $(NAME)