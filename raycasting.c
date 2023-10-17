/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:22:46 by ajeftani          #+#    #+#             */
/*   Updated: 2023/10/16 15:02:58 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void	my_mlx_pixel_put(t_data *data, int y, int x, int color)
// {
// 	unsigned char	*dst;

// 	dst = (unsigned char *)data->main->addr + (y * data->main->line_length + x
// * (data->main->bits_per_pixel / 8));
// 	*((unsigned int *)dst) = color;
// }

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
    
     double ray_angle = vars->player->angle - (FOV_ANGLE / 2);
     int x = 0;
     
    while (x < WIN_WIDTH)
    {  
         double ray_x = player_x;
         double ray_y = player_y;
         
         //double ray_angle = vars->player->angle - (FOV_ANGLE / 2) + (x * FOV_ANGLE) / WIN_WIDTH;
         
         while (1)
         {
            ray_x = ray_x + cos(ray_angle * M_PI / 180) * 0.5;
            ray_y = ray_y + sin(ray_angle * M_PI / 180) * 0.5;

             int map_x = (int)(ray_x / TILE_SIZE);
             int map_y = (int)(ray_y / TILE_SIZE);

             if (map_x < 0 || map_x >= WIN_WIDTH || map_y < 0 || map_y >= WIN_HEIGHT)
                 break;

           if (vars->map->map[map_y][map_x] == 49) // imagine
            {
                
                double delta_x = ray_x - player_x;
                double delta_y = ray_y - player_y;

                double distance_to_wall = sqrt(delta_x * delta_x + delta_y * delta_y);
                double corrected_distance = distance_to_wall * cos((ray_angle - vars->player->angle) * (M_PI / 180));
                double wall_height = (TILE_SIZE * WIN_HEIGHT) / corrected_distance;

                int column_x = x;
                
                mlx_draw_vertical_line(vars, column_x, (WIN_HEIGHT - wall_height) / 2, wall_height, 0xFF9900);

                break;
            }
       }
          ray_angle = ray_angle + 0.06;
            x++;
    }
    draw_mlx_map(vars,vars->mlx,vars->map);
}