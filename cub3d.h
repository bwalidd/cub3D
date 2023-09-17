/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:48:43 by wbouwach          #+#    #+#             */
/*   Updated: 2023/09/17 10:57:15 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include "mlx.h"
# include <stdlib.h>
# include "get_next_line/get_next_line.h"


# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define PI 3.14
# define TILE_SIZE 40

# define FOV_ANGLE (60 * (PI / 180)) // this is the field of view angle by radian
# define NUM_RAYS WINDOW_WIDTH

typedef struct	s_player
{
    int		x;
    int		y;
    int		dir;
    int     circle_radius;
    int     turn_direction;
    int     walk_direction;
    float		rotation_angle;
    float		walk_speed;
    float		turn_speed;
}				t_player;

typedef struct s_map_size
{
    char **map;
    int num_of_lines;
    int len_of_line;    
}       t_map_size;


typedef struct	s_mlx
{
    void	*mlx_ptr;
    void	*win_ptr;
    int bits_per_pixel;
    int size_line;
    int endian;
}				t_mlx;


void    init_window(t_mlx *g_mlx,t_map_size *map_info);
void    draw_mlx_map(char **map, t_mlx *g_mlx,t_map_size *map_info);
void    init_player(t_player *player);
void    init_player_pos(char **map,t_player *player,t_mlx *g_mlx);
void    draw_player(t_mlx *g_mlx, int x, int y);
//void    draw_line(void *win_ptr, void *mlx_ptr, int x1, int y1, int x2, int y2);
//void    draw_player(void *win_ptr, void *mlx_ptr, int x, int y);

#endif