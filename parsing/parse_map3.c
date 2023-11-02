/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:15:01 by wbouwach          #+#    #+#             */
/*   Updated: 2023/11/02 01:15:45 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_is_zero_surrounded(t_map_size *map_info)
{
	int	i;
	int	j;

	i = 1;
	while (map_info->map[i] && i < map_info->len_of_line - 1)
	{
		j = 1;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] == '0')
			{
				if (check_corners(map_info, i, j))
					ft_puterror("0 is not surrounded\n");
			}
			j++;
		}
		i++;
	}
}

void	check_inside_map(t_map_size *map_info, int i)
{
	if (i > 0 && i < map_info->num_of_lines - 1)
		check_is_closed(map_info->map, i);
}

void	check_map_cadre(t_map_size *map_info)
{
	int	i;

	i = 1;
	check_is_surrounded_by_wall(map_info->map, 0);
	check_is_surrounded_by_wall(map_info->map, map_info->num_of_lines - 1);
	while (map_info->map[i])
	{
		check_inside_map(map_info, i);
		i++;
	}
	check_is_zero_surrounded(map_info);
}

int	get_num_of_lines(char **content)
{
	int	i;
	int	j;

	i = 0;
	while (content[i] && content[i][0] != ' '
		&& content[i][0] != '1' && content[i][0] != '0')
		i++;
	j = i;
	while (content[i] && (content[i][0] == ' '
		|| content[i][0] == '1' || content[i][0] == '0'))
		i++;
	return (i - j);
}
