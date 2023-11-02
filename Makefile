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

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -O3 -g3

LINKS = -lmlx -framework OpenGL -framework AppKit

SRC = main.c raycasting/init_map.c raycasting/init_player.c raycasting/player_movements.c raycasting/raycasting.c\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
	parsing/parse_args.c parsing/parse_colors.c parsing/parse_map.c parsing/parse_map2.c parsing/parse_map3.c\
	parsing/parse_texture.c parsing/parser.c\
	helpers/ft_atoi.c helpers/ft_split.c helpers/ft_strdup.c helpers/ft_strncmp.c raycasting/set_direction.c\
	helpers/ft_strcmp.c helpers/ft_memcpy.c helpers/ft_isdigit.c textures.c raycasting/player_movement_ins.c raycasting/raycasting1.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re : fclean all

