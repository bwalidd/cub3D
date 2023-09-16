/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:52:08 by wbouwach          #+#    #+#             */
/*   Updated: 2023/09/16 00:38:07 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_player_pos(char **map,t_player *player,t_mlx *g_mlx)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
            {
                player->x = j;
                player->y = i;
                player->dir = map[i][j];
                map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
    //mlx_pixel_put(g_mlx->mlx_ptr,g_mlx->win_ptr,800,890,0xFFFF0000);
    init_player(player);
    draw_player(g_mlx, player->x, player->y);
}

void init_player(t_player *player)
{
    player->circle_radius = 3;
    player->rotation_angle = PI / 2;
    player->walk_speed = 5;
    player->turn_speed = 2 * (PI / 180);
    player->turn_direction = 0;
    player->walk_direction = 0;
}
/*
void draw_line(void *win_ptr, void *mlx_ptr, int x1, int y1, int x2, int y2)
{
    int i;
    int j;

    i = x1;
    while (i < x2)
    {
        j = y1;
        while (j < y2)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00FF0000);
            j++;
        }
        i++;
    }
}
*/

void draw_player(t_mlx *g_mlx, int x, int y)
{
    
    int i;
    int j;
    i = x * TILE_SIZE; // Use y for horizontal position
    while (i < ((x * TILE_SIZE) + (TILE_SIZE / 4)))
    {
        j = y * TILE_SIZE; // Use x for vertical position
        while (j < ((y * TILE_SIZE) + (TILE_SIZE / 4)))
        {
            mlx_pixel_put(g_mlx->mlx_ptr, g_mlx->win_ptr, i, j, 0x00FFFF00);
            j++;
        }
        i++;
    }
    // draw line to represent player direction
    // draw_line(win_ptr, mlx_ptr, x, y, x + 10, y);
}
