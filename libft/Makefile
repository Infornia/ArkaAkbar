#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdivry <cdivry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/18 19:45:35 by cdivry            #+#    #+#              #
#    Updated: 2015/10/23 11:01:16 by cdivry           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libft.a
CC		=	clang
SRC		=	ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_strdup.c\
			ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_putnbr.c ft_atoi.c\
			ft_memset.c ft_bzero.c ft_memcpy.c ft_strcat.c ft_strncat.c\
			ft_strlcat.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
			ft_putendl_fd.c ft_putendl.c ft_strstr.c ft_isalpha.c ft_isdigit.c\
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c\
			ft_strnew.c ft_itoa.c ft_strnstr.c ft_strchr.c ft_strrchr.c\
			ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c\
			ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
			ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
			ft_memdel.c ft_strdel.c ft_strsplit.c ft_lstnew.c ft_lstadd.c\
			ft_lstiter.c ft_lstdelone.c ft_lstdel.c ft_lstmap.c ft_nbrlen.c\
			ft_getnextline.c ft_isnum.c ft_free_tab.c ft_tab_add.c\
			ft_tab_count.c ft_tab_delone.c

INC	=	-I inc/
OBJ		=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:     all clean fclean re
