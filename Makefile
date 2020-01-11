#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 15:14:56 by xinwang           #+#    #+#              #
#    Updated: 2019/12/05 14:24:03 by xinwang          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

MAIN_FILE = ./src/main.c

SRCS_NAME = ft_printf.c ft_putchar.c is_conversion.c is_conversion_char.c \
	nb_char_to_skip.c do_conversion.c ft_itoa.c char_to_str.c ft_strnew.c ft_trans_x.c \
	ft_trans_X.c ptr_to_str.c ft_strlen.c ft_putstr.c manage_flags.c apply_flags.c \
	ft_extract_value_flag.c copy_str_at.c apply_precision.c ft_apply_width.c \
	replace_star.c ft_strcat.c free_str.c ft_strcmp.c add_hex_chars.c has_invalide_char_in_flag.c

SRCS_PATH = ./src/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

SRCSO = $(SRCS_NAME:.c=.o)

HEADER_DIR = ./include

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

all: ${NAME}

$(NAME): $(SRCO)
	$(CC) -c $(CC_FLAGS) $(SRCS) -I $(HEADER_DIR)
	ar rcs $(NAME) $(SRCSO)
	ranlib $(NAME)

main: all
	$(CC) $(MAIN_FILE) $(NAME) -I $(HEADER_DIR)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
