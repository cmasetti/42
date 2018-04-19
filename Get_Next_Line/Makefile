# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmasetti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 12:33:00 by cmasetti          #+#    #+#              #
#    Updated: 2018/02/26 17:24:00 by cmasetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = get_next_line

SRCS = 	get_next_line.c main.c

OBJ = $(SRCS:.c=.o)

PATH_LIB = libft/

LIB = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(PATH_LIB)$(LIB)

$(LIB):
	make -C $(PATH_LIB)

clean:
	rm -f $(OBJ)
	make clean -C $(PATH_LIB)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PATH_LIB)

re: fclean all

.PHONY: all clean fclean re
