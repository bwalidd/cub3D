/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:02:31 by ajeftani          #+#    #+#             */
/*   Updated: 2023/11/03 22:24:45 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	check_north_west(double w_y, double w_x, t_vars *vars)
{
	if ((int)(w_y + 0.05) % 50 == 0 && vars->map->map[(int)(w_y / 50.0)
		+ 1][(int)(w_x / 50.0)] == '0')
	{
		vars->player->where = w_x;
		return ('N');
	}
	else
	{
		vars->player->where = w_y;
		return ('W');
	}
}

char	check_north_east(double w_y, double w_x, t_vars *vars)
{
	if ((int)(w_y + 0.05) % 50 == 0 && vars->map->map[(int)((w_y / 50.0)
			+ 0.05)][(int)(w_x / 50.0)] == '0')
	{
		vars->player->where = w_x;
		return ('N');
	}
	else
	{
		vars->player->where = w_y;
		return ('E');
	}
}

char	check_south_east(double w_y, double w_x, t_vars *vars)
{
	if ((int)(w_y) % 50 == 0 && vars->map->map[(int)((w_y / 50.0)
			- 0.05)][(int)(w_x / 50.0)] == '0')
	{
		vars->player->where = w_x;
		return ('S');
	}
	else
	{
		vars->player->where = w_y;
		return ('E');
	}
}

char	check_south_west(double w_y, double w_x, t_vars *vars)
{
	if ((int)(w_y) % 50 == 0 && vars->map->map[(int)((w_y / 50.0)
			- 0.05)][(int)(w_x / 50.0)] == '0')
	{
		vars->player->where = w_x;
		return ('S');
	}
	else
	{
		vars->player->where = w_y;
		return ('W');
	}
}
