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
	draw_ceiling(vars, vars->map->color_c);
	draw_floor(vars, vars->map->color_f);
	raycasting(vars);
	return (0);
}

int	mouse_mv(int x, int y, t_vars *vars)
{
	if ((x >= 0 && x < WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT))
	{
		if (x > vars->player->x_mouse)
			vars->player->angle += 5;
		else
			vars->player->angle -= 5;
		vars->player->x_mouse = x;
	}
	return (0);
}
