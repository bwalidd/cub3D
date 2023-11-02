/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 01:34:38 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/23 01:34:38 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_chars(char c)
{
	if (c != 'W' && c != 'S' && c != 'E' && c != 'N')
	{
		return (1);
	}
	return (0);
}

void	check_double(t_map_size *map_info)
{
	int	i;
	int	j;
	int	found;

	found = 0;
	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (check_chars(map_info->map[i][j]) == 0)
				found++;
			j++;
		}
		i++;
	}
	if (found != 1)
	{
		write(2, "check their is one player\n", 27);
		exit (1);
	}
}

void	check_map(t_map_size *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (map_info->map[i])
	{
		j = 0;
		while (map_info->map[i][j])
		{
			if (map_info->map[i][j] != ' ' && map_info->map[i][j] != '1'
				&& map_info->map[i][j] != '0'
				&& check_chars(map_info->map[i][j]))
			{
				write(2, "there is a wrong char in your map\n", 35);
				exit (1);
			}
			j++;
		}
		i++;
	}
	check_double(map_info);
	check_map_cadre(map_info);
}

void	allocate_spaces(t_map_size *map_info)
{
	int	i;

	i = 0;
	while (map_info->map_content[i])
	{
		if (map_info->map_content[i][0] == ' '
			|| map_info->map_content[i][0] == '0'
			|| map_info->map_content[i][0] == '1')
		{
			if (map_info->len_of_line < ft_strlen(map_info->map_content[i]))
				map_info->len_of_line = ft_strlen(map_info->map_content[i]);
		}
		i++;
	}
	i = 0;
	while (i < map_info->num_of_lines)
	{
		map_info->map[i] = calloc(map_info->len_of_line, 1);
		i++;
	}
}

void	get_map(t_map_size *map_info)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	j = 0;
	map_info->len_of_line = 0;
	map_info->num_of_lines = get_num_of_lines(map_info->map_content);
	map_info->map = malloc(sizeof(char *) * (map_info->num_of_lines + 1));
	allocate_spaces(map_info);
	while (map_info->map_content[++i])
	{
		if (map_info->map_content[i][0] == ' '
			|| map_info->map_content[i][0] == '1'
			|| map_info->map_content[i][0] == '0')
		{
			fill_map(count, map_info, i, j);
			count++;
			j++;
		}
	}
	map_info->map[j] = NULL;
}
