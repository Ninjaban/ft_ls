#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/13 12:28:37 by jcarra            #+#    #+#              #
#    Updated: 2016/11/13 14:24:18 by jcarra           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	ft_ls

SRC			=	ft_flags.c \
				ft_main.c

LIB			=	libft.a

DIRSRC		=	sources/
DIRINC		=	include/
DIRLIB		=	library/

SRCS		=	$(SRC:%=$(DIRSRC)%)
OBJS		=	$(SRC:.c=.o)
LIBS		=	$(LIB:%=$(DIRLIB)%)

CFLAGS		=	-Wall -Wextra -Werror -I./$(DIRINC)

CC			=	gcc
RM			=	rm -f
ECHO		=	printf
MAKE		=	make -C


all		:		$(NAME)
			   	@$(ECHO) ''

$(NAME)	:
				@$(MAKE) $(DIRLIB)
				@$(CC) $(CFLAGS) -c $(SRCS)
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
				@$(ECHO) '\033[32m> $(NAME): Compiled\n\033[0m'

clean	:
				@$(MAKE) $(DIRLIB) clean
				@$(RM) $(OBJS)
				@$(ECHO) '\033[31m> $(NAME): Directory cleaned\n\033[0m'

fclean	:		clean
				@$(MAKE) $(DIRLIB) fclean
				@$(RM) $(NAME)
				@$(ECHO) '\033[31m> $(NAME): Remove executable\n\033[0m'

re		:		fclean all

.PHONY	:		all clean fclean re
