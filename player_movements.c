/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:18:41 by wbouwach          #+#    #+#             */
/*   Updated: 2023/09/28 22:20:17 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void update_player(t_mlx *g_mlx, t_player *player)
{
    mlx_clear_window(g_mlx->mlx_ptr, g_mlx->win_ptr);
    //draw_mlx_map(player->map_info->map, g_mlx, player->map_info);
    //printf("player x before: %d\n", player->x);
    //printf("player y before: %d\n", player->y);

    // Draw the player at the new position
    draw_mlx_map(player->map_info->map, g_mlx, player->map_info);
    draw_player(g_mlx, player);
    draw_line(g_mlx,player);
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
void rotate_player(t_player *player, int keycode)
{
    if (keycode == KEY_LEFT)
    {
        printf("left\n");
        player->rotation_angle -= player->turn_speed * player->turn_direction;
        printf("rotation angle: %f\n", player->rotation_angle);
    }
    else if (keycode == KEY_RIGHT)
    {
        printf("right\n");
        player->rotation_angle += player->turn_speed * player->turn_direction;
        printf("rotation angle: %f\n", player->rotation_angle);
    }
}

int key_press_hook(int keycode, t_player *player)
{
    float move_step = 1; // Adjust this for smoother/faster movement
    float rotation_step = 0.1; // Adjust this for smoother/faster rotation

    if (keycode == 'w') {
        // Calculate the movement in both x and y directions based on the rotation angle
        float move_x = cos(player->rotation_angle) * move_step;
        float move_y = sin(player->rotation_angle) * move_step;

        if (can_move(player->map_info->map, player->pixel_x + move_x, player->pixel_y + move_y, move_step, player)) {
            player->pixel_x += move_x;
            player->pixel_y += move_y;
        }
    } else if (keycode == 's') {
        // Calculate the opposite movement to go backward
        float move_x = cos(player->rotation_angle) * move_step;
        float move_y = sin(player->rotation_angle) * move_step;

        if (can_move(player->map_info->map, player->pixel_x - move_x, player->pixel_y - move_y, move_step, player)) {
            player->pixel_x -= move_x;
            player->pixel_y -= move_y;
        }
    } else if (keycode == 'a') {
        // Strafe left (move perpendicular to the current angle)
        float move_x = cos(player->rotation_angle - M_PI/2) * move_step;
        float move_y = sin(player->rotation_angle - M_PI/2) * move_step;

        if (can_move(player->map_info->map, player->pixel_x + move_x, player->pixel_y + move_y, move_step, player)) {
            player->pixel_x += move_x;
            player->pixel_y += move_y;
        }
    } else if (keycode == 'd') {
        // Strafe right (move perpendicular to the current angle)
        float move_x = cos(player->rotation_angle + M_PI/2) * move_step;
        float move_y = sin(player->rotation_angle + M_PI/2) * move_step;

        if (can_move(player->map_info->map, player->pixel_x + move_x, player->pixel_y + move_y, move_step, player)) {
            player->pixel_x += move_x;
            player->pixel_y += move_y;
        }
    } else {
        // Handle rotation for other keys
        if (keycode == KEY_LEFT) {
            player->rotation_angle -= rotation_step;
        } else if (keycode == KEY_RIGHT) {
            player->rotation_angle += rotation_step;
        }
    }

    update_player(player->g_mlx, player);

    return 0;
}



