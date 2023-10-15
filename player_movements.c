/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:18:41 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/14 17:28:27 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 //draw_line(vars, vars->player->x / 5, vars->player->y / 5, dest_x, dest_y, 0x0000FF);
void draw_line(t_vars *vars, int playerx, int playery, int destx, int desty, int color)
{
    int dx = abs(destx - playerx);
    int dy = abs(desty - playery);
    int sx = (playerx < destx) ? 1 : -1;
    int sy = (playery < desty) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr, playerx, playery, color);

        if (playerx == destx && playery == desty)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            playerx += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            playery += sy;
        }
    }
}


int key_press_hook(int keycode, t_vars *vars)
{
    if (keycode == 53) 
    {
        mlx_destroy_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);
        exit(0);
    }
    else if (keycode == 0) 
    {
        vars->player->angle -= 10.0;
    }
    else if (keycode == 2) 
    {
        vars->player->angle += 10.0;
    }
    else if (keycode == 13) 
    {
        double new_x = vars->player->pixel_x + PLAYER_SPEED * cos(vars->player->angle * M_PI / 180);
        double new_y = vars->player->pixel_y + PLAYER_SPEED * sin(vars->player->angle * M_PI / 180);
            int map_x = (int)(new_x / TILE_SIZE );
            int map_y = (int)(new_y / TILE_SIZE );
            if (vars->map->map[map_y][map_x] == 48) //maybe need more protection
           {
                vars->player->pixel_x =  new_x;
                vars->player->pixel_y =  new_y;
               vars->player->x = new_x;
               vars->player->y = new_y;
           }
    }
    else if (keycode == 1) 
    {
        double new_x = vars->player->pixel_x - PLAYER_SPEED * cos(vars->player->angle * M_PI / 180);
        double new_y = vars->player->pixel_y - PLAYER_SPEED * sin(vars->player->angle * M_PI / 180);
            int map_x = (int)(new_x / TILE_SIZE );
            int map_y = (int)(new_y / TILE_SIZE );
            if (vars->map->map[map_y][map_x] == 48) //maybe need more protection
           {
                vars->player->pixel_x =  new_x;
                vars->player->pixel_y =  new_y;
               vars->player->x = new_x;
               vars->player->y = new_y;
           }
    }
    mlx_clear_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);
    draw_mlx_map(vars,vars->mlx,vars->map);

    double angle_rad = vars->player->angle * M_PI / 180; 
    int distance_from_player = 50; 


    int dest_x = vars->player->x / 5 + distance_from_player * cos(angle_rad);
    int dest_y = vars->player->y / 5 + distance_from_player * sin(angle_rad);


    draw_line(vars, vars->player->x / 5, vars->player->y / 5, dest_x, dest_y, 0x000FF);
    raycasting(vars);
 

    return (0);
}


