# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:52:35 by myener            #+#    #+#              #
#    Updated: 2019/02/04 16:03:13 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = -I./

CFLAGS = -Wall -Wextra -Werror $(HEADERS)

OBJDIR	=	./objs

SRC = ft_atoi.c			\
	  ft_intlen.c		\
	  ft_lstnew.c		\
	  ft_lstdelone.c	\
	  ft_lstdel.c		\
	  ft_lstadd.c		\
	  ft_lstiter.c		\
	  ft_lstmap.c		\
	  ft_isalnum.c		\
	  ft_isalpha.c		\
	  ft_isascii.c		\
	  ft_isblank.c		\
	  ft_isdigit.c		\
	  ft_isprint.c		\
	  ft_itoa.c			\
	  ft_memcpy.c		\
	  ft_memset.c		\
	  ft_strcat.c		\
	  ft_strchr.c		\
	  ft_strcmp.c		\
	  ft_strcpy.c		\
	  ft_strdup.c		\
	  ft_strlen.c		\
	  ft_strncat.c		\
	  ft_strncmp.c		\
	  ft_strncpy.c		\
	  ft_strrchr.c		\
	  ft_tolower.c		\
	  ft_toupper.c		\
	  ft_bzero.c		\
	  ft_memccpy.c		\
	  ft_memchr.c		\
	  ft_memcmp.c		\
	  ft_memmove.c		\
	  ft_strlcat.c		\
	  ft_strstr.c		\
	  ft_strnstr.c		\
	  ft_memalloc.c		\
	  ft_memdel.c		\
	  ft_strnew.c		\
	  ft_strndup.c		\
	  ft_strdel.c		\
	  ft_strnlen.c		\
	  ft_strclr.c		\
	  ft_striter.c		\
	  ft_striteri.c		\
	  ft_putchar.c		\
	  ft_putchar_fd.c	\
	  ft_putendl.c		\
	  ft_putendl_fd.c	\
	  ft_putstr.c		\
	  ft_putstr_fd.c	\
	  ft_putnbr.c		\
	  ft_putnbr_fd.c	\
	  ft_strmap.c		\
	  ft_strmapi.c		\
	  ft_strequ.c		\
	  ft_strnequ.c		\
	  ft_strsub.c		\
	  ft_strjoin.c		\
	  ft_strsplit.c		\
	  ft_strtrim.c		\
	  ft_strrev.c		\
	  get_next_line.c

OBJECTS = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

$(OBJDIR)/%.o:	%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
