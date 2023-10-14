/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:22:46 by ajeftani          #+#    #+#             */
/*   Updated: 2023/10/14 13:02:10 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void mlx_draw_vertical_line(t_vars *vars, int x, int y, int height, int color)
{
    //int x is column x which is 0 ;
    //int y is the rest of screen vertically divided by two which is 2 and total of 4.
    // int height is the height of the wall


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
    
    double ray_angle = vars->player->angle - (FOV_ANGLE / 2);
     int x = 0;

    while (x < WIN_WIDTH)
    {  
        //double ray_angle = vars->player.angle - (FOV_ANGLE / 2) + (x * FOV_ANGLE) / WIN_WIDTH;
        double ray_x = player_x;
        double ray_y = player_y;

        while (1)
        {
            ray_x = ray_x + cos(ray_angle * M_PI / 180) * 1.0;
            ray_y = ray_y + sin(ray_angle * M_PI / 180) * 1.0;

            int map_x = (int)(ray_x / TILE_SIZE);
            int map_y = (int)(ray_y / TILE_SIZE);

            if (map_x < 0 || map_x >= WIN_WIDTH || map_y < 0 || map_y >= WIN_HEIGHT)
                break;

            if (vars->map->map[map_y][map_x] == 48)
            {
                
                double delta_x = ray_x - player_x;
                double delta_y = ray_y - player_y;

                double distance_to_wall = sqrt(delta_x * delta_x + delta_y * delta_y);


                double wall_height = (TILE_SIZE * WIN_HEIGHT) / distance_to_wall;

                int column_x = x;
                
                mlx_draw_vertical_line(vars, column_x, (WIN_HEIGHT - wall_height) / 2, wall_height, 0xFF0000);

                break;
            }
        }
            x++;
            ray_angle += 0.06;
    }
}

// void raycasting(t_vars *vars)
// {
//     double ray_angle = vars->player->angle - FOV_ANGLE / 2;
//     double player_x = vars->player->x;
//     double player_y = vars->player->y;

//    while (ray_angle <= vars->player->angle + FOV_ANGLE / 2) 
//     {
//         double ray_x = player_x;
//         double ray_y = player_y;
//         double ray_distance = 0;

//         while (ray_distance < WIN_WIDTH / 5) 
//         {
//             ray_x += (cos(ray_angle * M_PI / 180) * 1.0);
//             ray_y += (sin(ray_angle * M_PI / 180) * 1.0);
            
//             int map_x = (int)(ray_x / TILE_SIZE );
//             int map_y = (int)(ray_y / TILE_SIZE );
//             if (vars->map->map[map_y][map_x] == 49) 
//             {
//                 break;
//             }

//             mlx_pixel_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr, ray_x / 5, ray_y / 5, 0xFF0000);
//             ray_distance += 1.0;

//         }

//         ray_angle += 1.0;
        
//     }
//     draw_ray(vars);
// }
