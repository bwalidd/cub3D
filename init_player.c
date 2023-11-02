/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeftani <ajeftani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:52:08 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/16 06:26:52 by ajeftani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_player_pos(char **map, t_player *player, t_mlx *g_mlx, t_map_size *infos, t_vars *vars)
{

	int	i;
	int	j;
	(void)g_mlx;
	(void)infos;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j]) 
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				player->x = j;
				player->y = i;
				player->dir = map[i][j];
				player->pixel_x = j * TILE_SIZE;
				player->pixel_y = i * TILE_SIZE;
				vars->player->x = vars->player->x * TILE_SIZE;
				vars->player->y = vars->player->y * TILE_SIZE;

				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
