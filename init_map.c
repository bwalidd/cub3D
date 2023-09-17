/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:08:37 by wbouwach          #+#    #+#             */
/*   Updated: 2023/09/17 11:07:25 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_window(t_mlx *g_mlx,t_map_size *map_info)
{
    g_mlx->mlx_ptr = mlx_init();
    g_mlx->win_ptr = mlx_new_window(g_mlx->mlx_ptr, map_info->len_of_line * TILE_SIZE, map_info->num_of_lines * TILE_SIZE, "Cub3D");
}
/*
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
}*/

void draw_mlx_map(char **map, t_mlx *g_mlx,t_map_size *map_info)
{
    int i;
    int j;
    int x;
    int y;
    void *img; // Image object
    int color;
    int *img_data;
    // Create an image with the same dimensions as the window
    img = mlx_new_image(g_mlx->mlx_ptr, map_info->len_of_line * TILE_SIZE, map_info->num_of_lines * TILE_SIZE);
    img_data = (int *)mlx_get_data_addr(img, &g_mlx->bits_per_pixel, &g_mlx->size_line, &g_mlx->endian);
    i = 0;
    y = 0;
    while (map[i])
    {
        j = 0;
        x = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                color = 0x00FF0000;
            else if (map[i][j] == '0')
                color = 0x00000000;
            else if (map[i][j] == '2')
                color = 0x0000FF00;

            // Calculate the position in the image data array
            for (int rect_y = 0; rect_y < TILE_SIZE; rect_y++)
            {
                for (int rect_x = 0; rect_x < TILE_SIZE; rect_x++)
                {
                    int position = ((y + rect_y) * (TILE_SIZE * map_info->len_of_line)) + (x + rect_x);
                    img_data[position] = color;
                }
            }
            j++;
            x += TILE_SIZE;
        }
        i++;
        y += TILE_SIZE;
    }
    mlx_put_image_to_window(g_mlx->mlx_ptr, g_mlx->win_ptr, img, 0, 0);
}




