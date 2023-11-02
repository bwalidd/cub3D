/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:18:41 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/17 13:06:10 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_vars *vars, int playerx, int playery, int destx, int desty,
		int color)
{
	int dx = abs(destx - playerx);
	int dy = abs(desty - playery);
	int sx = (playerx < destx) ? 1 : -1;
	int sy = (playery < desty) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		mlx_pixel_put(vars->mlx->mlx_ptr, vars->mlx->win_ptr, playerx, playery,
			color);

		if (playerx == destx && playery == desty)
			break ;

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

void	draw_ceiling(t_vars *vars, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			my_mlx_pixel_put(vars->data, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_floor(t_vars *vars, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = WIN_HEIGHT / 2;
		while (y < WIN_HEIGHT)
		{
			my_mlx_pixel_put(vars->data, x, y, color);
			y++;
		}
		x++;
	}
}

int	moving(t_vars *vars)
{
	double	angle_rad;
	int		distance_from_player;

	if (vars->player->turn_left == 1)
		vars->player->angle -= 5.0;
	if (vars->player->turn_right == 1)
		vars->player->angle += 5.0;
	if (vars->player->move_forward == 1)
		go_ahead(vars);
	if (vars->player->move_backward == 1)
		go_back(vars);
	if (vars->player->slide_r == 1)
		slide_right(vars);
	if (vars->player->slide_l == 1)
		slide_left(vars);
	mlx_clear_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);
	angle_rad = vars->player->angle * M_PI / 180;
	distance_from_player = 50;
	int dest_x = vars->player->x / 5 + distance_from_player * cos(angle_rad);
	int dest_y = vars->player->y / 5 + distance_from_player * sin(angle_rad);
	draw_ceiling(vars, vars->map->color_c);
	draw_floor(vars, vars->map->color_f);
	raycasting(vars);
	draw_line(vars, vars->player->x / 5, vars->player->y / 5, dest_x,
	dest_y,
		0xFF1100);
	return (0);
}
