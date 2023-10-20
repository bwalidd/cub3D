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
        if (ft_strncmp(map_info->map_content[*i],"NO",3) == 0)
            line++;
        else if (ft_strncmp(map_info->map_content[*i],"SO",3) == 0)
            line++;
        else if (ft_strncmp(map_info->map_content[*i],"WE",3) == 0)
            line++;
        else if (ft_strncmp(map_info->map_content[*i],"EA",3) == 0)
            line++;
        (*i)++;
   }
    if (line != 4)
    {
        write(2,"wrong texture format\n",21);
        exit(1);
    }
}