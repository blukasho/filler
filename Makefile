#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/07/13 12:43:18 by blukasho          #+#    #+#             *#
#*   Updated: 2019/07/26 11:56:45 by blukasho         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

SRCS = read.c clear.c map.c piece.c game.c set.c

SRCS_DIR = srcs/

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

OBJ_DIR = obj/

LIBFT_PATH = libft/

LIB_NAME = libft/libft.a

FILLER = blukasho.filler

FLAGS = -Wall -Wextra -Werror -I includes

DEBUG_FLAGS = -g3 -fsanitize=address

NAME_MAIN = srcs/main.c

all: make_objs_dir make_lib $(FILLER)

$(FILLER): $(LIB_NAME) $(NAME_MAIN)
	gcc $(FLAGS) $(NAME_MAIN) $(LIB_NAME) -o $(FILLER)

$(LIB_NAME): $(OBJ)
	ar -rv $(LIB_NAME) $^
	ranlib $(LIB_NAME)

set_debug_flags:
	$(eval FLAGS=$(FLAGS) $(DEBUG_FLAGS))

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	gcc $(FLAGS) -c $< -o $@

debug: make_debug_lib set_debug_flags all

make_debug_lib:
	make debug -C $(LIBFT_PATH)

make_objs_dir:
	@mkdir -p $(OBJ_DIR)

make_lib:
	@make -C $(LIBFT_PATH)

make_clean_lib:
	make clean -C $(LIBFT_PATH)

clean: make_clean_lib
	rm -rf $(OBJ_DIR) 

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rvf blukasho.filler.dSYM
	rm -rvf filler.trace
	rm -rvf $(FILLER)

re: fclean all

.PHONY: all clean fclean re debug
