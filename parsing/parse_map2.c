/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:26:08 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/26 01:08:54 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_wall(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}


void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	exit(1);
}

void	check_is_surrounded_by_wall(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j] && map[i][j] == ' ')
		j++;
	if (!map[i][j] || map[i][j] != '1')
		ft_puterror("invalid map\n");
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			ft_puterror("invalid map hihi\n");
		j++;
	}
}

void	check_is_closed(char **map, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(map[i]);
	while (map[i][j] && map[i][j] != '1')
	{
		if (map[i][j] != ' ')
			ft_puterror("invalid map (not start by one)\n");
		j++;
	}
	while (map[i][len - 1] == ' ')
		len--;
	if (map[i][len - 1] != '1')
	{
		ft_puterror("invalid map (not end by one)\n");
	}
}

int	check_corners(t_map_size *map_info, int i, int j)
{
	if ((i > 0 && i < map_info->num_of_lines - 1))
	{
		if (j >= ft_strlen(map_info->map[i + 1])
			|| j >= ft_strlen(map_info->map[i - 1]))
			return (1);
	}
	if (map_info->map[i + 1][j] == ' ')
		return (1);
	if (map_info->map[i - 1][j] == ' ')
		return (1);
	if (!map_info->map[i][j + 1] || map_info->map[i][j + 1] == ' ')
		return (1);
	if (!map_info->map[i][j - 1] || map_info->map[i][j - 1] == ' ')
		return (1);
	return (0);
}
