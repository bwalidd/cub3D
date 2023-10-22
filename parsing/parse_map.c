/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:40:52 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/19 15:40:52 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int get_num_of_lines(char **content)
{
    int i;

    i = 0;
    while (content[i] && (content[i][0] != ' ' || content[i][0] != '1' || content[i][0] != '0'))
        i++;
    i = 0;
    while (content[i] && (content[i][0] == ' ' || content[i][0] == '1' || content[i][0] == '0'))
        i++;
    return (i);
}


void get_map(t_map_size *map_info)
{
    int i;
    int j;

    i = 0;
    j = 0;
    map_info->len_of_line = 0;
    map_info->num_of_lines = get_num_of_lines(map_info->map_content);
    map_info->map = malloc(sizeof(char *) * (map_info->num_of_lines + 1));
    while (map_info->map_content[i])
    {
        if(map_info->map_content[i][0] == ' ' || map_info->map_content[i][0] == '1' || map_info->map_content[i][0] == '0')
        {
            map_info->map[j] = ft_strdup(map_info->map_content[i]);
            j++;
            if(map_info->len_of_line < ft_strlen(map_info->map_content[j - 1]))
                map_info->len_of_line = ft_strlen(map_info->map_content[j - 1]);
        }
        i++;
    }
    map_info->map[j] = NULL;
}