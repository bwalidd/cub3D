/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:08:37 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/17 10:35:05 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_window(t_mlx *g_mlx,t_map_size *map_info, t_data *data)
{
    (void)map_info;
    g_mlx->mlx_ptr = mlx_init();
    g_mlx->win_ptr = mlx_new_window(g_mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT , "Cub3D");
    data->img = mlx_new_image(g_mlx->mlx_ptr,WIN_WIDTH,WIN_HEIGHT);
    data->addr = mlx_get_data_addr(data->img,&data->bits_per_pixel,&data->line_length,&data->endian);
}

void draw_rect(t_mlx *g_mlx, int x, int y, int width, int height, int color) 
{
    int i = x;
    while (i < x + width) 
    {
        int j = y;
        while (j < y + height) 
            {
                if (i >= 0) 
                {
                   mlx_pixel_put(g_mlx->mlx_ptr, g_mlx->win_ptr, i, j, color);
                }
                j++;
            }
        i++;
    }
}

void draw_mlx_map( t_vars *vars ,t_mlx *g_mlx, t_map_size *map_info) 
{
    (void)vars;
    int i = 0;
    int j = 0;

    while (i < map_info->num_of_lines) 
    {
        j = 0;
        while (j < ft_strlen(map_info->map[i])) 
        {
            if (map_info->map[i][j] == 49) 
            {
                draw_rect(g_mlx, j * TILE_SIZE / 5 , i * TILE_SIZE / 5 , TILE_SIZE / 5, TILE_SIZE / 5, 0x00FF00);
            }
            j++;
        }
        i++;
    }
    // Draw the player as a larger yellow rectangle
        draw_rect(g_mlx,vars->player->pixel_x / 5 - 5 ,vars->player->pixel_y / 5 - 5, TILE_SIZE / 5, TILE_SIZE / 5, 0xFFFF00);
}