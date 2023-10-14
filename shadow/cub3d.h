/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:48:43 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/14 09:35:17 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include "get_next_line/get_next_line.h"


# define KEY_W 'w'
# define KEY_S 's'
# define KEY_A 'a'
# define KEY_D 'd'
# define KEY_DOWN  65364
# define KEY_LEFT  65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_ESC 53
#define WIN_WIDTH 1000
#define WIN_HEIGHT 700
#define TILE_SIZE 50
#define FOV_ANGLE 60
#define PLAYER_SPEED 10.0

# define NUM_RAYS WINDOW_WIDTH

typedef struct s_map_size
{
    char **map;
    int num_of_lines;
    int number_horizontal;    
} t_map_size;

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;
    int bits_per_pixel;
    int size_line;
    int endian;
} t_mlx;

typedef struct s_player {
    int   x ;
    int   y ;
    int      dir;
    float    pixel_x;
    float    pixel_y;
    double   angle;
} t_player;

typedef struct s_vars {
    t_map_size *map;
    t_mlx *mlx;
    t_player *player;
} t_vars;

void raycasting(t_vars *vars);
void init_window(t_mlx *g_mlx, t_map_size *map_info);
void draw_mlx_map( t_vars *vars ,t_mlx *g_mlx, t_map_size *map_info);
void init_player(t_player *player, t_map_size *infos, t_mlx *g_mlx);
void init_player_pos(char **map, t_player *player, t_mlx *g_mlx, t_map_size *infos);
void draw_player(t_mlx *g_mlx, t_player *player);
void update_player(t_mlx *g_mlx, t_player *player);
int key_press_hook(int keycode, t_vars *vars);
void draw_rect(t_mlx *g_mlx, int x, int y, int width, int height, int color);

#endif