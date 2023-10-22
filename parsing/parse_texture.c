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

void parse_texture(t_map_size *map_info,int *i)
{
   int line;

   line = 0;
   while (*i < 4 && map_info->map_content[*i])
   {
        if (ft_strncmp(map_info->map_content[*i],"NO",2) == 0)
            line++;
        else if (ft_strncmp(map_info->map_content[*i],"SO",2) == 0)
            line++;
        else if (ft_strncmp(map_info->map_content[*i],"WE",2) == 0)
            line++;
        else if (ft_strncmp(map_info->map_content[*i],"EA",2) == 0)
            line++;
        (*i)++;
   }
    if (line != 4)
    {
        write(2,"wrong texture format\n",21);
        exit(1);
    }
}


void get_map_textures(t_map_size *map_info)
{
    char **splitted;
    int i;

    i = 0;
    while (i < 4)
    {
        splitted = ft_split(map_info->map_content[i], ' ');
        if (ft_strncmp(splitted[0],"NO",3) == 0)
            map_info->no_texture = ft_strdup(splitted[1]);
        else if (ft_strncmp(splitted[0],"SO",3) == 0)
            map_info->so_texture = ft_strdup(splitted[1]);
        else if (ft_strncmp(splitted[0],"WE",3) == 0)
            map_info->we_texture = ft_strdup(splitted[1]);
        else if (ft_strncmp(splitted[0],"EA",3) == 0)
            map_info->ea_texture = ft_strdup(splitted[1]);
        free(splitted);
        i++;
    }
    if (map_info->no_texture == NULL || map_info->so_texture == NULL || map_info->we_texture == NULL || map_info->ea_texture == NULL)
    {
        write(2,"wrong texture format\n",21);
        exit(1);
    }
}