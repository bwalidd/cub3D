/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 09:22:46 by ajeftani          #+#    #+#             */
/*   Updated: 2023/10/17 13:03:03 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH
		&& y >= 0 && y < WIN_HEIGHT)
	{
		dst = data->addr
			+ (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
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



void	mlx_draw_vertical_line(t_vars *vars, int x, int y, int height, char dir)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (dir == 'N')
			my_mlx_pixel_put(vars->data, x, y + i,
				*(unsigned int *)north_textures(vars, i));
		else if (dir == 'E') 
			my_mlx_pixel_put(vars->data, x, y + i, 0xFF0000);
		else if (dir == 'S')
			my_mlx_pixel_put(vars->data, x, y + i, 0xFF00FF);
		else if (dir == 'W')
			my_mlx_pixel_put(vars->data, x, y + i, 0xFF0000);
		else
			my_mlx_pixel_put(vars->data, x, y + i, 0xFF0000);
		i++;
	}
}


char	check_north_west(double w_y, double w_x, t_vars *vars)
{
	if ((int)(w_y + 1) % 50 == 0
		&& vars->map->map[(int)(w_y / 50.0) + 1][(int)(w_x / 50.0)] == '0')
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
	if ((int)(w_y + 0.05) % 50 == 0
		&& vars->map->map[(int)((w_y / 50.0) + 0.05)][(int)(w_x / 50.0)] == '0')
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
	if ((int)(w_y) % 50 == 0 && vars->map->map[(int)((w_y / 50.0) - 0.05)][(int)(w_x / 50.0)] == '0')
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
	if ((int)(w_y) % 50 == 0
		&& vars->map->map[(int)((w_y / 50.0) - 0.05)][(int)(w_x / 50.0)] == '0')
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

void raycasting(t_vars *vars)
{
	double player_x = vars->player->x;
	double player_y = vars->player->y;
	vars->player->dir = '\0';
	
	double ray_angle = vars->player->angle - (FOV_ANGLE / 2);
	int x = 0;

	draw_ceiling(vars, vars->map->color_c);
	draw_floor(vars,vars->map->color_f);
	
	mlx_put_image_to_window(vars->mlx->mlx_ptr,vars->mlx->win_ptr, vars->data->img, 0,0);
	 
	while (x < WIN_WIDTH)
	{  
		 double ray_x = player_x;
		 double ray_y = player_y;
		 
		 while (1)
		 {
			ray_x = ray_x + cos(ray_angle * M_PI / 180) * 0.05;
			ray_y = ray_y + sin(ray_angle * M_PI / 180) * 0.05;

			 int map_x = (int)(ray_x / TILE_SIZE);
			 int map_y = (int)(ray_y / TILE_SIZE);

			 if (map_x < 0 || map_x >= WIN_WIDTH || map_y < 0 || map_y >= WIN_HEIGHT)
				 break;

		   if (vars->map->map[map_y][map_x] == 49) // imagine
			{
				double delta_x = ray_x - player_x;
				double delta_y = ray_y - player_y;

				double distance_to_wall = sqrt(delta_x * delta_x + delta_y * delta_y);
				vars->mlx->corrected_distance = distance_to_wall * cos((ray_angle - vars->player->angle) * (M_PI / 180));
				vars->mlx->wall_height = (TILE_SIZE * WIN_HEIGHT) / vars->mlx->corrected_distance;
				int column_x = x;
				vars->player->dir = set_directions(ray_y,ray_x,vars);
				vars->player->where = (int)(vars->player->where * (1000.0 / 50.0)) % 1000;
				mlx_draw_vertical_line(vars, column_x, (WIN_HEIGHT -  vars->mlx->wall_height) / 2,  vars->mlx->wall_height, vars->player->dir);
				break;
			}
	   }
		  ray_angle = ray_angle + 0.06;
			x++;
	}
	mlx_put_image_to_window(vars->mlx->mlx_ptr,vars->mlx->win_ptr, vars->data->img, 0,0);
	draw_mlx_map(vars,vars->mlx,vars->map);
}