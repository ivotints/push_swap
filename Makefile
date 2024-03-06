# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 13:00:11 by ivotints          #+#    #+#              #
#    Updated: 2024/02/16 16:38:04 by ivotints         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PRINTF = libftprintf.a

SRC_FILES = push_swap.c sort_utils.c \
		sort_move2.c sort_move.c sort_functions.c \
		super_checker.c super_checker2.c super_checker3.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = ${SRC:.c=.o}
OBJBB = ${filter-out src/push_swap.o ,${OBJ}}
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
FSANITIZE	= -fsanitize=address -g3
LDFLAGS = -L $(SRC_DIR)
INCLUDE = -I include
RM = rm -f

all:		$(NAME)

$(NAME) : $(OBJ)
		@make -C lib
		@cp lib/libftprintf.a .
		$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(PRINTF) -o $(NAME)

clean :
		@make clean -C lib
		@${RM} ${OBJ}

fclean : clean
		@make fclean -C lib
		@${RM} ${NAME} $(PRINTF)

re : fclean all

.PHONY	:	all clean fclean re

