# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpole <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 10:08:31 by bpole             #+#    #+#              #
#    Updated: 2019/12/01 21:12:32 by bpole            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_F = bpole.filler
#NAME_P = push_swap

LIB_DIR = ./ft_printf/
LIBFT = $(LIB_DIR)libftprintf.a

SRC_F = main.c read_fil.c utils.c read_piece.c thinker.c head_map.c search_solution.c

#SRC_P = ./push_swap.c ./commands.c ./solver_algo.c ./util.c \
        ./get_commands.c ./commands_next.c ./do_commands.c \
        ./creat_stack.c ./separate.c ./free_or_del.c

OBJ_F = $(SRC_F:.c=.o)
#OBJ_P = $(SRC_P:.c=.o)

INCLUDE = filler.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME_F) #$(NAME_P)

%.o: %.c
	$(CC) -c $(FLAGS) $<

$(NAME_F): $(OBJ_F)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAGS) -o $(NAME_F) $(OBJ_F) $(LIBFT)

#$(NAME_P): $(OBJ_P)
#	$(CC) $(FLAGS) -o $(NAME_P) $(OBJ_P) $(LIBFT)
# rm -rf $(OBJ_C) $(OBJ_P)
clean:
	rm -rf $(OBJ_F)
	$(MAKE) -C $(LIB_DIR) clean
#rm -rf $(NAME_C) $(NAME_P)
fclean: clean
	rm -rf $(NAME_F)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all