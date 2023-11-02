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

#include "../cub3d.h"
void check_direction_view(t_player *player, t_vars *vars,int i,int j)
{
				player->x = j;
				player->y = i;
				player->pixel_x = j * TILE_SIZE;
				player->pixel_y = i * TILE_SIZE;
				vars->player->x = vars->player->x * TILE_SIZE;
				vars->player->y = vars->player->y * TILE_SIZE;
}
void	init_player_pos(char **map, t_player *player, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				check_direction_view(player,vars,i,j);
				player->dir = map[i][j];
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
