# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 16:21:39 by mribouch          #+#    #+#              #
#    Updated: 2019/02/04 16:03:35 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	:= make
CC		:= gcc
LD		:= gcc
RM		:= rm -rf

SRCDIR	:=	./
OBJDIR	:=	./objs
INCLDIR	:=	-I./libft
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

OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))
LIB		:=	$(LIBDIR)/libft.a
NAME	:=	fillit

$(NAME): $(LIB) $(OBJS)
	@printf "\e[32m  Creating: \e[0m$(NAME)\n"
	@$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

$(LIB):
	$(MAKE) -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[32m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "\e[32m  Cleaning: \e[0m$(OBJDIR)\e[0m\n"
	@$(RM) $(OBJDIR)
	$(MAKE) -C libft clean

fclean: clean
	@printf "\e[32m  Removing: \e[0m"
	@find . -name "fillit" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
