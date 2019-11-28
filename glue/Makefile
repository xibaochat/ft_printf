#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 15:14:56 by xinwang           #+#    #+#              #
#    Updated: 2019/11/28 15:30:41 by xinwang          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_printf

MAIN_FILE = main.c

SRCS_NAME = ${MAIN_FILE} ft_printf.c ft_putchar.c

SRCS_PATH = ./src/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

HEADER_DIR = ./include


all:
	gcc ${SRCS} -I ${HEADER_DIR} -o ${NAME}

fclean:
	rm -f $(NAME)
