# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:14:10 by abolor-e          #+#    #+#              #
#    Updated: 2023/11/16 13:43:21 by abolor-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

SRCS		= ft_printf.c	\
			  ft_nputchar.c	\
			  ft_nputnbr.c	\
			  ft_pputnbr.c	\
			  ft_nputstr.c	\
			  ft_lowhexa.c	\
			  ft_upphexa.c	\
			  ft_putaddr.c	

OBJS		= ${SRCS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
		ar -rcs ${NAME} ${OBJS}

%.o:		%.c
		${CC} ${CFLAGS} -c $< -o $@

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


