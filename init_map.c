/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:08:37 by wbouwach          #+#    #+#             */
/*   Updated: 2023/09/16 12:57:32 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void    init_window(t_mlx *g_mlx,t_map_size *map_info)
{
    g_mlx->mlx_ptr = mlx_init();
    g_mlx->win_ptr = mlx_new_window(g_mlx->mlx_ptr, map_info->len_of_line * TILE_SIZE, map_info->num_of_lines * TILE_SIZE, "Cub3D");
}

static void fill_rectangle(t_mlx *g_mlx, int x, int y, int width, int height, int color)
{
    int rect_x = 0;
    while (rect_x < width)
    {
        int rect_y = 0;
        while (rect_y < height)
        {
            mlx_pixel_put(g_mlx->mlx_ptr, g_mlx->win_ptr, x + rect_x, y + rect_y, color);
            rect_y++;
        }
        rect_x++;
    }
}

void draw_mlx_map(char **map, t_mlx *g_mlx)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    y = 0;
    while (map[i])
    {
        j = 0;
        x = 0;
        while (map[i][j])
        {
            int rect_width = TILE_SIZE;
            int rect_height = TILE_SIZE;
            int color;
            if (map[i][j] == '1')
                color = 0x00FF0000;
            else if (map[i][j] == '0')
                color = 0x00000000;
            else if (map[i][j] == '2')
                color = 0x0000FF00;
            //else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
              //  color = 0x000000FF;
            fill_rectangle(g_mlx, x, y, rect_width, rect_height, color);
            j++;
            x += TILE_SIZE;
        }
        i++;
        y += TILE_SIZE;
    }
}

