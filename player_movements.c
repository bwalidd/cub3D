/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:18:41 by wbouwach          #+#    #+#             */
/*   Updated: 2023/09/22 23:22:28 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void update_player(t_mlx *g_mlx, t_player *player)
{
    mlx_clear_window(g_mlx->mlx_ptr, g_mlx->win_ptr);
    draw_mlx_map(player->map_info->map, g_mlx, player->map_info);
    //printf("player x before: %d\n", player->x);
    //printf("player y before: %d\n", player->y);

    // Draw the player at the new position
    draw_mlx_map(player->map_info->map, g_mlx, player->map_info);
    draw_player(g_mlx, player);
}

int key_press_hook(int keycode, t_player *player)
{
    float move_step = 2; // Adjust this for smoother/faster movement

    if (keycode == KEY_UP || keycode == 'w')
    {
        printf("w before%f\n",player->pixel_y);
        player->pixel_y -= move_step;
        printf("w after%f\n",player->pixel_y);
    }
    else if (keycode == KEY_DOWN || keycode == 's')
    {
        printf("s before%f\n",player->pixel_y);
        player->pixel_y += move_step;
        printf("s after%f\n",player->pixel_y);
    }
    else if (keycode == KEY_LEFT || keycode == 'a')
    {
        printf("a before%f\n",player->pixel_x);
        player->pixel_x -= move_step;
        printf("a after%f\n",player->pixel_x);
    }
    else if (keycode == KEY_RIGHT || keycode == 'd')
    {
        printf("d before%f\n",player->pixel_x);
        player->pixel_x += move_step;
        printf("d after%f\n",player->pixel_x);
    }
    update_player(player->g_mlx,player);
    return 0;
}


