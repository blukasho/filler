#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/07/13 12:43:18 by blukasho          #+#    #+#             *#
#*   Updated: 2019/07/30 14:02:17 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


NAME = blukasho.filler

SRCS = read.c clear.c map.c piece.c game.c set.c main.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -I includes -I libft/includes

LIB = libft/libft.a

all: $(LIB) $(NAME)

$(OBJ): %.o: srcs/%.c
	gcc -c $(FLAGS) $< -o $@

$(NAME): $(OBJ)
	gcc $(OBJ) $(LIB) -o $(NAME) 

$(LIB):
	make -C libft/

clean:
	rm -rf libft/objs
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(LIB)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
