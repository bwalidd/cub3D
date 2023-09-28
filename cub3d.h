/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:48:43 by wbouwach          #+#    #+#             */
/*   Updated: 2023/09/28 14:51:31 by wbouwach         ###   ########.fr       */
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
# define PI 3.14
# define TILE_SIZE 40

# define FOV_ANGLE (60 * (PI / 180)) // this is the field of view angle by radian
# define NUM_RAYS WINDOW_WIDTH


typedef struct s_map_size
{
    char **map;
    int num_of_lines;
    int len_of_line;    
} t_map_size;

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;
    int bits_per_pixel;
    int size_line;
    int endian;
} t_mlx;

typedef struct s_player
{
    float x;
    float y;
    int dir;
    int circle_radius;
    int turn_direction;
    int walk_direction;
    float rotation_angle;
    float walk_speed;
    float     target_x;
    float     pixel_x;
    float      pixel_y;
    float     target_y;
    float turn_speed;
    t_map_size *map_info;
    t_mlx *g_mlx;
} t_player;

void init_window(t_mlx *g_mlx, t_map_size *map_info);
void draw_mlx_map(char **map, t_mlx *g_mlx, t_map_size *map_info);
void init_player(t_player *player, t_map_size *infos, t_mlx *g_mlx);
void init_player_pos(char **map, t_player *player, t_mlx *g_mlx, t_map_size *infos);
void draw_player(t_mlx *g_mlx, t_player *player);
void update_player(t_mlx *g_mlx, t_player *player);
int key_press_hook(int keycode, t_player *player);
void draw_line(t_mlx *g_mlx, t_player *player);

#endif