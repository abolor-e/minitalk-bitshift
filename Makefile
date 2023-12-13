# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abolor-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 10:42:28 by abolor-e          #+#    #+#              #
#    Updated: 2023/12/12 14:23:58 by abolor-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES		= server
NAMEC		= client

SRCC		= client.c
SRCS		= server.c

OBJC		= ${SRCC:.c=.o}
OBJS		= ${SRCS:.c=.o}

PRINTF		= ./printf/libftprintf.a

LIBFT		= ./libft/libft.a

RM			= rm -rf

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -g3 -g -fsanitize=address

all:		${NAMES} ${NAMEC}

${PRINTF}:	
	${MAKE} -C ./printf

${LIBFT}:
	${MAKE} -C ./libft

${NAMEC}:	${OBJC} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${OBJC} ${LIBFT} ${PRINTF} -o client

${NAMES}:	${OBJS} ${LIBFT} ${PRINTF}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${PRINTF} -o server

clean:
	${MAKE} clean -C ./printf
	${MAKE} clean -C ./libft
	${RM} ${OBJS} ${OBJC}

fclean:		clean
	${MAKE} fclean -C ./printf
	${MAKE} fclean -C ./libft
	${RM} ${NAMEC} ${NAMES}

re:			fclean all

.PHONY:		all clean fclean re
