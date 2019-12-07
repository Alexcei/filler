# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpole <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 10:08:31 by bpole             #+#    #+#              #
#    Updated: 2019/12/07 15:05:09 by bpole            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual_fil

LIB_DIR = ../ft_printf/

LIBFT = $(LIB_DIR)libftprintf.a

SRC = main.c utils.c render.c bresenham.c control.c transform.c \
        read_fight.c double_split.c head_map.c loop_key_hook.c \
        mouse_press.c read_payer.c creat_imag.c

OBJ = $(SRC:.c=.o)

INCLUDE = ./

CC = gcc

FLAGS =  -Wall -Wextra -Werror

FRAEM = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $<

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAGS) -I $(INCLUDE) -o $(NAME) $(OBJ) $(LIBFT) $(LIBFT_X) $(FRAEM)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
