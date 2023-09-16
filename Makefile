# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 20:28:46 by wbouwach          #+#    #+#              #
#    Updated: 2023/09/15 19:33:53 by wbouwach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

LINKS = -L/usr/local/lib -lmlx -lX11 -lXext -lm

SRC = main.c init_map.c init_player.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	
re : fclean all

