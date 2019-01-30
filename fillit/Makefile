# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 16:21:39 by mribouch          #+#    #+#              #
#    Updated: 2019/01/30 18:51:54 by mribouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS	=	main.c				\
			check.c				\
			check_neighbour.c	\
			tools.c				\
			get.c				\
			map.c				\
			put_up_left.c		\
			solver.c
OBJS	=	$(SRCS:.c=.o)

FLAGS			=	-Wall -Wextra -Werror
LIBFT_FOLDER	=	libft

all: libft $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $(NAME) -I $(LIBFT_FOLDER) $(LIBFT_FOLDER)/libft.a

.c.o: $(SRCS)
	gcc -c $< -o $@ $(FLAGS)

libft:
	make -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: libft clean fclean re