# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 20:28:46 by wbouwach          #+#    #+#              #
#    Updated: 2023/10/19 01:32:26 by wbouwach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

LINKS = -lmlx -framework OpenGL -framework AppKit

SRC = main.c init_map.c init_player.c player_movements.c raycasting.c\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
	parsing/parse_args.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re : fclean all

