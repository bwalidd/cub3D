/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:38:52 by ajeftani          #+#    #+#             */
/*   Updated: 2023/11/02 10:24:26 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall_hit(t_vars *vars)
{
	double	ray_angle;
	int		map_x;
	int		map_y;

	vars->ray_angle = vars->player->angle - (FOV_ANGLE / 2);
	while (vars->x < WIN_WIDTH)
	{
		vars->ray_x = vars->player_x;
		vars->ray_y = vars->player_y;
		while (1)
		{
			vars->ray_x = vars->ray_x + cos(ray_angle * M_PI / 180) * 0.05;
			vars->ray_y = vars->ray_y + sin(ray_angle * M_PI / 180) * 0.05;
			map_x = (int)(vars->ray_x / TILE_SIZE);
			map_y = (int)(vars->ray_y / TILE_SIZE);
			if (vars->map->map[map_y][map_x] == 49
				|| vars->map->map[map_y][map_x] == '\0'
				|| vars->map->map[map_y][map_x] == '\n'
				|| vars->map->map[map_y][map_x] == ' ')
			{
				vars->ray_angle = ray_angle;
				draw_it(vars);
				break ;
			}
		}
		ray_angle = ray_angle + 0.06;
		vars->x++;
	}
}

char	set_directions(double w_y, double w_x, t_vars *vars)
{
	if (vars->player->pixel_y > w_y && vars->player->pixel_x > w_x)
		return (check_north_west(w_y, w_x, vars));
	else if (vars->player->pixel_y > w_y && vars->player->pixel_x < w_x)
		return (check_north_east(w_y, w_x, vars));
	else if (vars->player->pixel_y <= w_y && vars->player->pixel_x <= w_x)
		return (check_south_east(w_y, w_x, vars));
	else if (vars->player->pixel_y <= w_y && vars->player->pixel_x >= w_x)
		return (check_south_west(w_y, w_x, vars));
	return (0);
}

void	mlx_draw_vertical_line(t_vars *vars, int x, int y, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (vars->player->dir == 'N')
			my_mlx_pixel_put(vars->data, x, y + i,
				*(unsigned int *)north_textures(vars, i));
		else if (vars->player->dir == 'E')
			my_mlx_pixel_put(vars->data, x, y + i,
				*(unsigned int *)east_textures(vars, i));
		else if (vars->player->dir == 'S')
			my_mlx_pixel_put(vars->data, x, y + i,
				*(unsigned int *)south_textures(vars, i));
		else if (vars->player->dir == 'W')
			my_mlx_pixel_put(vars->data, x, y + i,
				*(unsigned int *)west_textures(vars, i));
		else
			my_mlx_pixel_put(vars->data, x, y + i, 0xFF0000);
		i++;
	}
}

void	draw_it(t_vars *vars)
{
	double	distance_to_wall;
	int		column_x;

	vars->delta_x = vars->ray_x - vars->player_x;
	vars->delta_y = vars->ray_y - vars->player_y;
	distance_to_wall = sqrt(vars->delta_x * vars->delta_x + vars->delta_y
			* vars->delta_y);
	vars->mlx->corrected_distance = distance_to_wall * cos((vars->ray_angle
				- vars->player->angle) * (M_PI / 180));
	vars->mlx->wall_height = (TILE_SIZE * WIN_HEIGHT)
		/ vars->mlx->corrected_distance;
	column_x = vars->x;
	vars->player->dir = set_directions(vars->ray_y, vars->ray_x, vars);
	vars->player->where = (int)(vars->player->where * (1000.0 / 50.0)) % 1000;
	mlx_draw_vertical_line(vars, column_x, (WIN_HEIGHT - vars->mlx->wall_height)
		/ 2, vars->mlx->wall_height);
}
