# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 19:30:59 by elilliu           #+#    #+#              #
#    Updated: 2024/12/19 17:46:59 by elilliu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE = include/philo.h

SRCS_DIR = srcs

SRCS = main.c utils.c data_init.c verif_args.c 

OBJS_DIR = objs

OBJS = ${addprefix ${OBJS_DIR}/, ${SRCS:.c=.o}}

CC = cc
CFLAGS = -Wall -Wextra -Werror

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${INCLUDE}
		mkdir -p ${OBJS_DIR}
		${CC} ${CFLAGS} -c $< -o $@ -g3

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o $@

all: ${NAME}

clean:
		rm -rf ${OBJS_DIR}

fclean: clean;
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ${OBJS_DIR}
