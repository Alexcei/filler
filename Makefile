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

LIB_DIR = ./ft_printf/
LIBFT = $(LIB_DIR)libftprintf.a

SRC_F = main.c read_fil.c utils.c read_piece.c\
        thinker.c head_map.c search_solution.c

OBJ_F = $(SRC_F:.c=.o)

INCLUDE = filler.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME_F)

%.o: %.c
	$(CC) -c $(FLAGS) $<

$(NAME_F): $(OBJ_F)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAGS) -o $(NAME_F) $(OBJ_F) $(LIBFT)

clean:
	rm -rf $(OBJ_F)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME_F)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all