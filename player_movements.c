/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:18:41 by wbouwach          #+#    #+#             */
/*   Updated: 2023/09/25 21:47:23 by wbouwach         ###   ########.fr       */
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

int can_move(char **map, float x, float y, float move_step,t_player *player)
{
    // Calculate the new position after moving
    int new_map_x = (int)((x + move_step) / TILE_SIZE);
    int new_map_y = (int)((y + move_step) / TILE_SIZE);

    // Check if the new position is within the map boundaries
    if (new_map_x < 0 || new_map_y < 0 || new_map_y >= player->map_info->num_of_lines * TILE_SIZE || new_map_x >= player->map_info->len_of_line * TILE_SIZE) {
        return 0; // Player is out of bounds
    }

    // Check if the new position contains '0' (empty space) in the map
    return map[new_map_y][new_map_x] == '0';
}


int key_press_hook(int keycode, t_player *player)
{
    float move_step = 1; // Adjust this for smoother/faster movement

    if (keycode == KEY_UP || keycode == 'w')
    {
        if (can_move(player->map_info->map, player->pixel_x, player->pixel_y - move_step - 1, move_step, player))
        {
            player->pixel_y -= move_step;
        }
    }
    else if (keycode == KEY_DOWN || keycode == 's')
    {
        if (can_move(player->map_info->map, player->pixel_x, player->pixel_y + move_step - 1, move_step, player))
        {
            player->pixel_y += move_step;
        }
    }
    else if (keycode == KEY_LEFT || keycode == 'a')
    {
        if (can_move(player->map_info->map, player->pixel_x - move_step - 1, player->pixel_y, move_step, player))
        {
            player->pixel_x -= move_step;
        }
    }
    else if (keycode == KEY_RIGHT || keycode == 'd')
    {
        if (can_move(player->map_info->map, player->pixel_x + move_step - 1, player->pixel_y, move_step, player))
        {
            player->pixel_x += move_step;
        }
    }
    update_player(player->g_mlx, player);
    return 0;
}



