/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:19:58 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/19 16:19:58 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int calc_lines(char *str)
{
    int i;
    int fd;

    i = 0;
    fd = open(str,O_RDONLY);
    while(get_next_line(fd) != NULL)
        i++;
    close(fd);
    return i;
}


static void get_cub_file_info(char *str,t_map_size *map_info)
{
    int fd;
    int len_of_line;
    len_of_line = calc_lines(str);
    map_info->map_content = (char **)malloc(sizeof(char *) * (len_of_line + 1));
    fd = open(str,O_RDONLY);
    int i = 0;
    while (i < len_of_line)
    {
        map_info->map_content[i] = get_next_line(fd);
        i++;
    }
    map_info->map_content[i] = NULL;
    close(fd);
}

static int  parse_is_here_map(t_map_size *map_info)
{
    int i = 0;
    while(map_info->map_content[i])
    {
        if (map_info->map_content[i][0] == ' ' || map_info->map_content[i][0] == '0'
        || map_info->map_content[i][0] == '1')
            return 0;
        i++;
    }
    return 1;
}

static void check_content_order(t_map_size *map_info)
{
    int i = 0;
    parse_texture(map_info, &i);
    while (map_info->map_content[i] && ft_strcmp(map_info->map_content[i],"\n") == 0)
        i++;
    parse_color(map_info);
    if (parse_is_here_map(map_info))
    {
        write(2,"no map detected\n",17);
        exit (1);
    }
}


int parsing(char *str,t_map_size *map_info)
{
    if (get_file_extension(str))
        return 1;
    get_cub_file_info(str,map_info);
    check_content_order(map_info);
    get_map_textures(map_info);
    get_map(map_info);
    return 0;
}