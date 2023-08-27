/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:08:37 by wbouwach          #+#    #+#             */
/*   Updated: 2023/08/27 21:08:37 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void    init_play_pos(char **map)
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
                g_player.x = j;
                g_player.y = i;
                g_player.dir = map[i][j];
                map[i][j] = '0';
            }
            j++;
        }
        i++;
    } 
}

void    init_window(void)
{
    g_mlx.mlx_ptr = mlx_init();
    g_mlx.win_ptr = mlx_new_window(g_mlx.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
}

void  draw_mlx_map(char **map, void *win_ptr, void *mlx_ptr)
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
            if (map[i][j] == '1')
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FF0000);
            else if (map[i][j] == '0')
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00000000);
            else if (map[i][j] == '2')
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000FF00);
            else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x000000FF);
            j++;
            x++;
        }
        i++;
        y++;
    }
}