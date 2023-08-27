/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:48:43 by wbouwach          #+#    #+#             */
/*   Updated: 2023/08/27 20:48:43 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define M_PI 3.14
# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20
# define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
# define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

# define FOV_ANGLE (60 * (M_PI / 180)) // this is the field of view angle by radian
# define NUM_RAYS WINDOW_WIDTH

typedef struct	s_player
{
    int		x;
    int		y;
    int		dir;
    float		rotation_angle;
    float		walk_speed;
    float		turn_speed;
}				t_player;


typedef struct	s_mlx
{
    void	*mlx_ptr;
    void	*win_ptr;
}				t_mlx;