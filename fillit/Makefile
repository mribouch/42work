# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 16:21:39 by mribouch          #+#    #+#              #
#    Updated: 2019/01/28 16:44:20 by mribouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c check.c check_neighbour.c \
		tools.c get.c map.c put_up_left.c solver.c

FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) check.o check_neighbour.o main.o \
	libft/libft.a tools.o get.o map.o put_up_left.o solver.o -o $(NAME)

clean:
	rm -f check.o check_neighbour.o main.o tools.o get.o map.o \
	put_up_left.o solver.o
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
