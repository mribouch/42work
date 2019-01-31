# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 16:21:39 by mribouch          #+#    #+#              #
#    Updated: 2019/01/31 12:16:29 by mribouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	:= make
CC		:= gcc
LD		:= gcc
RM		:= rm -rf

SRCDIR	:=	./
INCLDIR	:=	-I libft/includes
LIBDIR 	:=	libft/

CFLAGS	:=	-Wall -Wextra -Werror $(INCLDIR)
LDFLAGS	:=	-L$(LIBDIR) -lft

SRCS    :=	main.c				\
			check.c				\
			check_neighbour.c	\
			tools.c				\
			get.c				\
			map.c				\
			put_up_left.c		\
			solver.c
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:=	$(patsubst %.c,%.o,$(SRCS))
DEPS	:=	Makefile fillit.h
LIB		:=	$(LIBDIR)/libft.a
NAME	:=	fillit

all: $(NAME)

$(LIB):
	@$(MAKE) -C libft/

$(NAME): $(LIB) $(OBJS)
	@echo "\033[32m  Creating: \033[0m$(NAME)"
	@$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	@printf "\033[32m Compiling: \033[0m$< -> $@\n"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "\033[32m  Cleaning: \033[0m$(OBJS)\033[0m\n"
	@$(RM) $(OBJS)
	@$(MAKE) -C libft clean

fclean: clean
	@printf "\033[32m  Removing: \033[0m"
	@find . -name "fillit" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
