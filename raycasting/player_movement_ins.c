/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_ins.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:03:14 by ajeftani          #+#    #+#             */
/*   Updated: 2023/11/02 12:17:07 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	go_ahead(t_vars *vars)
{
	vars->new_x = vars->player->pixel_x + PLAYER_SPEED * cos(vars->player->angle
			* M_PI / 180);
	vars->new_y = vars->player->pixel_y + PLAYER_SPEED * sin(vars->player->angle
			* M_PI / 180);
	vars->map_x = (int)(vars->new_x / TILE_SIZE);
	vars->map_y = (int)(vars->new_y / TILE_SIZE);
	if (vars->map->map[vars->map_y][vars->map_x] == 48)
	{
		vars->player->pixel_x = vars->new_x;
		vars->player->pixel_y = vars->new_y;
		vars->player->x = vars->new_x;
		vars->player->y = vars->new_y;
	}
}

void	go_back(t_vars *vars)
{
	vars->new_x = vars->player->pixel_x - PLAYER_SPEED * cos(vars->player->angle
			* M_PI / 180);
	vars->new_y = vars->player->pixel_y - PLAYER_SPEED * sin(vars->player->angle
			* M_PI / 180);
	vars->map_x = (int)(vars->new_x / TILE_SIZE);
	vars->map_y = (int)(vars->new_y / TILE_SIZE);
	if (vars->map->map[vars->map_y][vars->map_x] == 48)
	{
		vars->player->pixel_x = vars->new_x;
		vars->player->pixel_y = vars->new_y;
		vars->player->x = vars->new_x;
		vars->player->y = vars->new_y;
	}
}

void	slide_right(t_vars *vars)
{
	vars->new_x = vars->player->pixel_x - PLAYER_SPEED
		* cos((vars->player->angle - 90.0) * M_PI / 180);
	vars->new_y = vars->player->pixel_y - PLAYER_SPEED
		* sin((vars->player->angle - 90.0) * M_PI / 180);
	vars->map_x = (int)(vars->new_x / TILE_SIZE);
	vars->map_y = (int)(vars->new_y / TILE_SIZE);
	if (vars->map->map[vars->map_y][vars->map_x] == 48)
	{
		vars->player->pixel_x = vars->new_x;
		vars->player->pixel_y = vars->new_y;
		vars->player->x = vars->new_x;
		vars->player->y = vars->new_y;
	}
}

void	slide_left(t_vars *vars)
{
	vars->new_x = vars->player->pixel_x + PLAYER_SPEED
		* cos((vars->player->angle - 90.0) * M_PI / 180);
	vars->new_y = vars->player->pixel_y + PLAYER_SPEED
		* sin((vars->player->angle - 90.0) * M_PI / 180);
	vars->map_x = (int)(vars->new_x / TILE_SIZE);
	vars->map_y = (int)(vars->new_y / TILE_SIZE);
	if (vars->map->map[vars->map_y][vars->map_x] == 48)
	{
		vars->player->pixel_x = vars->new_x;
		vars->player->pixel_y = vars->new_y;
		vars->player->x = vars->new_x;
		vars->player->y = vars->new_y;
	}
}
