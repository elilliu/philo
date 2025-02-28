# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elilliu <elilliu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 19:30:59 by elilliu           #+#    #+#              #
#    Updated: 2025/02/28 19:40:01 by elilliu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE = include/philo.h

SRCS_DIR = srcs

SRCS = main.c utils.c data_init.c verif_args.c \
		routine.c other_actions.c has_prio.c ft_eat.c \
		memory_errors.c

OBJS_DIR = objs

OBJS = ${addprefix ${OBJS_DIR}/, ${SRCS:.c=.o}}

CC = cc
CFLAGS = -Wall -Wextra -Werror
# -fsanitize=thread -g

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${INCLUDE}
		mkdir -p ${OBJS_DIR}
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o $@

all: ${NAME}

clean:
		rm -rf ${OBJS_DIR}

fclean: clean;
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ${OBJS_DIR}
