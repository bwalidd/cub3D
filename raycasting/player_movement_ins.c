/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_ins.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:03:14 by ajeftani          #+#    #+#             */
/*   Updated: 2023/11/03 23:01:58 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_collision(t_vars *vars, float x, float y)
{
	int	mapx;
	int	mapy;

	mapx = (int)floor(x / 50);
	mapy = (int)floor(y / 50);
	if (vars->map->map[mapy][mapx] == '1')
	{
		return (0);
	}
	return (1);
}

void	go_ahead(t_vars *vars)
{
	vars->new_x = vars->player->pixel_x + PLAYER_SPEED * cos(vars->player->angle
			* M_PI / 180);
	vars->new_y = vars->player->pixel_y + PLAYER_SPEED * sin(vars->player->angle
			* M_PI / 180);
	if (check_collision(vars, vars->new_x - 10, vars->player->pixel_y - 10)
		&& check_collision(vars, vars->player->pixel_x - 10, vars->new_y - 10)
		&& check_collision(vars, vars->new_x + 10, vars->player->pixel_y + 10)
		&& check_collision(vars, vars->player->pixel_x + 10, vars->new_y + 10))
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
	if (check_collision(vars, vars->new_x - 10, vars->player->pixel_y - 10)
		&& check_collision(vars, vars->player->pixel_x - 10, vars->new_y - 10)
		&& check_collision(vars, vars->new_x + 10, vars->player->pixel_y + 10)
		&& check_collision(vars, vars->player->pixel_x + 10, vars->new_y + 10))
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
	if (check_collision(vars, vars->new_x - 10, vars->player->pixel_y - 10)
		&& check_collision(vars, vars->player->pixel_x - 10, vars->new_y - 10)
		&& check_collision(vars, vars->new_x + 10, vars->player->pixel_y + 10)
		&& check_collision(vars, vars->player->pixel_x + 10, vars->new_y + 10))
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
	if (check_collision(vars, vars->new_x - 10, vars->player->pixel_y - 10)
		&& check_collision(vars, vars->player->pixel_x - 10, vars->new_y - 10)
		&& check_collision(vars, vars->new_x + 10, vars->player->pixel_y + 10)
		&& check_collision(vars, vars->player->pixel_x + 10, vars->new_y + 10))
	{
		vars->player->pixel_x = vars->new_x;
		vars->player->pixel_y = vars->new_y;
		vars->player->x = vars->new_x;
		vars->player->y = vars->new_y;
	}
}
