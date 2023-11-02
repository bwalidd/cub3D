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

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

void	raycasting(t_vars *vars)
{
	vars->player_x = vars->player->x;
	vars->player_y = vars->player->y;
	vars->player->dir = '\0';
	vars->x = 0;
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->data->img, 0, 0);
	wall_hit(vars);
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->data->img, 0, 0);
	draw_mlx_map(vars, vars->mlx, vars->map);
}
