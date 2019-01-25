# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mribouch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 16:21:39 by mribouch          #+#    #+#              #
#    Updated: 2019/01/23 16:21:12 by mribouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c ../get_next_line/get_next_line.c check.c check_neighbour.c \
		tools.c get.c map.c put_up_left.c solver.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	gcc -Wall -Wextra -Werror check.o check_neighbour.o main.o get_next_line.o \
	libft/libft.a tools.o get.o map.o put_up_left.o solver.o -o $(NAME)

clean:
	rm -f check.o check_neighbour.o main.o get_next_line.o tools.o get.o map.o \
	put_up_left.o solver.o

fclean: clean
	rm -f $(NAME)
re: fclean all
