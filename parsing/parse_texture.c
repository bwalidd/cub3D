/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:16:47 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/20 16:16:47 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_texture_and_color(t_map_size *map_info, int *i)
{
	int	line;

	line = 0;
	while (map_info->map_content[*i])
	{
		if (ft_strncmp(map_info->map_content[*i], "NO", 2) == 0)
			line++;
		else if (ft_strncmp(map_info->map_content[*i], "SO", 2) == 0)
			line++;
		else if (ft_strncmp(map_info->map_content[*i], "WE", 2) == 0)
			line++;
		else if (ft_strncmp(map_info->map_content[*i], "EA", 2) == 0)
			line++;
		else if (ft_strncmp(map_info->map_content[*i], "F", 1) == 0)
			line++;
		else if (ft_strncmp(map_info->map_content[*i], "C", 1) == 0)
			line++;
		(*i)++;
	}
	if (line != 6)
		ft_puterror("wrong texture and color format\n");
}

static void	init_textures(t_map_size *map_info)
{
	map_info->so_texture = NULL;
	map_info->no_texture = NULL;
	map_info->ea_texture = NULL;
	map_info->we_texture = NULL;
}

void	fill_textures(t_map_size *map_info, char **splitted, int *flag)
{
	if (ft_strncmp(splitted[0], "NO", 2) == 0)
	{
		map_info->no_texture = ft_strndup(splitted[1],
				ft_strlen(splitted[1]) - 2);
		(*flag)++;
	}
	else if (ft_strncmp(splitted[0], "SO", 2) == 0)
	{
		map_info->so_texture = ft_strndup(splitted[1],
				ft_strlen(splitted[1]) - 2);
		(*flag)++;
	}
	else if (ft_strncmp(splitted[0], "WE", 2) == 0)
	{
		map_info->we_texture = ft_strndup(splitted[1],
				ft_strlen(splitted[1]) - 2);
		(*flag)++;
	}
	else if (ft_strncmp(splitted[0], "EA", 2) == 0)
	{
		map_info->ea_texture = ft_strndup(splitted[1],
				ft_strlen(splitted[1]) - 2);
		(*flag)++;
	}
}

void	get_map_textures(t_map_size *map_info)
{
	char	**splitted;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	init_textures(map_info);
	while (1)
	{
		splitted = ft_split(map_info->map_content[i], ' ');
		fill_textures(map_info, splitted, &flag);
		free(splitted);
		if (flag == 4)
			break ;
		i++;
	}
	if (map_info->no_texture == NULL || map_info->so_texture == NULL
		|| map_info->we_texture == NULL || map_info->ea_texture == NULL)
	{
		write(2, "a texture null\n", 16);
		exit(1);
	}
}
