/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:48:04 by wbouwach          #+#    #+#             */
/*   Updated: 2023/11/02 22:48:55 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*west_textures(t_vars *vars, int i)
{
	int	x;
	int	y;

	x = (int)round(vars->player->where);
	if (vars->mlx->wall_height > WIN_HEIGHT)
		y = (int)(round)((i + (vars->mlx->wall_height - WIN_HEIGHT) / 2.0)
				* (1000.0 / vars->mlx->wall_height)) % 1000;
	else
		y = (int)round(i * (1000.0 / vars->mlx->wall_height)) % 1000;
	vars->mlx->color = vars->mlx->addr_w + (y * vars->mlx->l_len_w + (x * 4));
	return (vars->mlx->color);
}

char	*east_textures(t_vars *vars, int i)
{
	int	x;
	int	y;

	x = (int)round(vars->player->where);
	if (vars->mlx->wall_height > WIN_HEIGHT)
		y = (int)(round)((i + (vars->mlx->wall_height - WIN_HEIGHT) / 2.0)
				* (1000.0 / vars->mlx->wall_height)) % 1000;
	else
		y = (int)round(i * (1000.0 / vars->mlx->wall_height)) % 1000;
	vars->mlx->color = vars->mlx->addr_e + (y * vars->mlx->l_len_e + (x * 4));
	return (vars->mlx->color);
}
