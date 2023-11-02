/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:47:58 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/19 01:45:06 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_hook(int key, t_vars *vars)
{
	if (key == 123)
		vars->player->turn_left = 1;
	if (key == 124)
		vars->player->turn_right = 1;
	if (key == 13)
		vars->player->move_forward = 1;
	if (key == 1)
		vars->player->move_backward = 1;
	if (key == 2)
		vars->player->slide_r = 1;
	if (key == 0)
		vars->player->slide_l = 1;
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);
		exit(0);
	}
	return (0);
}

int	relesse_key(int key, t_vars *vars)
{
	if (key == 123)
		vars->player->turn_left = 0;
	if (key == 124)
		vars->player->turn_right = 0;
	if (key == 13)
		vars->player->move_forward = 0;
	if (key == 1)
		vars->player->move_backward = 0;
	if (key == 2)
		vars->player->slide_r = 0;
	if (key == 0)
		vars->player->slide_l = 0;
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

int	ft_cross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_map_size	*map_info;
	t_player	*player;
	t_mlx		*g_mlx;
	t_vars		*vars;
	t_data		*data;

	if (ac < 2)
		return (0);
	map_info = malloc(sizeof(t_map_size));
	if (parsing(av[1], map_info))
	   return (1);
	//t_data *data;
	//data = malloc(sizeof(t_data));
	player = malloc(sizeof(t_player));
	vars = malloc(sizeof(t_vars));
	data = malloc(sizeof(t_data));
	vars->data = data;
	vars->player = player;
	vars->map = map_info;
	g_mlx = malloc(sizeof(t_mlx));
	vars->mlx = g_mlx;
	init_window(g_mlx,data);
	img_to_xpm(vars);
	init_player_pos(map_info->map, player,vars);
	draw_mlx_map(vars, g_mlx, map_info);
	raycasting(vars);
	mlx_hook(g_mlx->win_ptr, 2, 1L << 0, key_press_hook, vars);
	mlx_hook(g_mlx->win_ptr, 3, 1L << 1, relesse_key, vars);
	mlx_hook(g_mlx->win_ptr, 17, 0, ft_cross, vars);
	mlx_hook(g_mlx->win_ptr, 6, 1L << 6, mouse_mv, vars);
	mlx_loop_hook(g_mlx->mlx_ptr, moving, vars);
	mlx_loop(g_mlx->mlx_ptr);
	return (0);
}
