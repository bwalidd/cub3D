/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:52:08 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/13 15:06:14 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_player_pos(char **map,t_player *player,t_mlx *g_mlx,t_map_size *infos)
{

    (void)g_mlx;
    (void)infos;
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
                player->pixel_x = j * TILE_SIZE;
                player->pixel_y = i * TILE_SIZE;
                map[i][j] = '0';
            }
            j++;
        }
        i++;
    }
    //printf(" x origin %f\n",player->pixel_x);
    //printf(" y origin %f\n",player->pixel_y);
    //draw_rect(g_mlx,player->pixel_x / 5 ,player->pixel_y / 5, TILE_SIZE / 5, TILE_SIZE / 5, 0xFFFF00);
    //init_player(player,infos, g_mlx);
    //draw_player(g_mlx, player);
}


// void init_player(t_player *player,t_map_size *infos,t_mlx *g_mlx)
// {
//     player->map_info = infos;
//     player->g_mlx = g_mlx;
//     player->circle_radius = 3;
//     player->rotation_angle = PI / 2;
//     player->walk_speed = 2;
//     player->turn_speed = 2 * (PI / 180);
//     player->turn_direction = 1;
//     player->walk_direction = 1;
//     player->num_rays = infos->len_of_line;
// }

// void draw_line(void *win_ptr, void *mlx_ptr, int x1, int y1, int x2, int y2)
// {
//     int i;
//     int j;

//     i = x1;
//     while (i < x2)
//     {
//         j = y1;
//         while (j < y2)
//         {
//             mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0x00FF0000);
//             j++;
//         }
//         i++;
//     }
// }

// void draw_line(t_mlx *g_mlx, t_player *player)
// {
//     float x1 = player->pixel_x;
//     float y1 = player->pixel_y;
//     float x2 = x1 + cos(player->rotation_angle) * 40;
//     float y2 = y1 + sin(player->rotation_angle) * 40;

//     float dx = fabs(x2 - x1);
//     float dy = fabs(y2 - y1);

//     int steps;
//     if (dx > dy)
//         steps = round(dx);
//     else
//         steps = round(dy);

//     float x_increment = (x2 - x1) / steps;
//     float y_increment = (y2 - y1) / steps;

//     float x = x1;
//     float y = y1;

//     int i = 0;
//     while (i < steps)
//     {
//         mlx_pixel_put(g_mlx->mlx_ptr, g_mlx->win_ptr, round(x), round(y), 0x00FF0000);
//         x += x_increment;
//         y += y_increment;
//         i++;
//     }
// }

//  void draw_player(t_mlx *g_mlx, t_player *player)
//  {
//     // Convert pixel coordinates to map coordinates
//     float map_x = player->pixel_x / TILE_SIZE;
//     float map_y = player->pixel_y / TILE_SIZE;

//     float i;
//     float j;

//     i = map_x * TILE_SIZE;
//     while (i < (map_x * TILE_SIZE + TILE_SIZE / 40))
//     {
//         j = map_y * TILE_SIZE;
//         while (j < (map_y * TILE_SIZE + TILE_SIZE / 40))
//         {
//             mlx_pixel_put(g_mlx->mlx_ptr, g_mlx->win_ptr, i, j, 0x00FFFF00);
//             j++;
//         }
//         i++;
//     }
//     draw_line(g_mlx, player);
// }

