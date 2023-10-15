/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:22:46 by ajeftani          #+#    #+#             */
/*   Updated: 2023/10/15 13:28:21 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void mlx_draw_vertical_line(t_vars *vars, int x, int y, int height, int color)
{
    int i = 0;
    while (i < height) 
    {
        mlx_pixel_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr, x, y + i, color);
        i++;
    }
}

void raycasting(t_vars *vars)
{
     double player_x = vars->player->x;
     double player_y = vars->player->y;
    
    // double ray_angle = vars->player->angle - (FOV_ANGLE / 2);
     int x = 0;

    while (x < vars->map->map_width)
    {  
       double ray_angle = vars->player->angle - (FOV_ANGLE / 2) + (x * FOV_ANGLE) / vars->map->map_width;
         double ray_x = player_x;
         double ray_y = player_y;

         while (1)
         {
            ray_x = ray_x + cos(ray_angle * M_PI / 180) * 1.0;
            ray_y = ray_y + sin(ray_angle * M_PI / 180) * 1.0;

             int map_x = (int)(ray_x / TILE_SIZE);
             int map_y = (int)(ray_y / TILE_SIZE);

             if (map_x < 0 || map_x >= vars->map->map_width || map_y < 0 || map_y >= vars->map->map_height)
                 break;

           if (vars->map->map[map_y][map_x] == 49) // imagine
            {
                
                double delta_x = ray_x - player_x;
                double delta_y = ray_y - player_y;

                double distance_to_wall = sqrt(delta_x * delta_x + delta_y * delta_y);

                double wall_height = (TILE_SIZE * vars->map->map_height) / distance_to_wall;

                int column_x = x;

                mlx_draw_vertical_line(vars, column_x, (vars->map->map_height - wall_height) / 2, wall_height, 0xFF0000);

                break;
            }
       }
            x++;
    }
}