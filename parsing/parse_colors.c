/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:32:58 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/20 16:32:58 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void parse_color2(t_map_size *map_info,int *color_c,int *color_f)
{
    if (color_c[0] < 0 || color_c[0] > 255 || color_c[1] < 0 || color_c[1] > 255 || color_c[2] < 0 || color_c[2] > 255)
    {
        write(2,"wrong color range\n", 19);
        exit(1);
    }
    if (color_f[0] < 0 || color_f[0] > 255 || color_f[1] < 0 || color_f[1] > 255 || color_f[2] < 0 || color_f[2] > 255)
    {
        write(2,"wrong color range\n", 19);
        exit(1);
    }
    map_info->color_c = color_c[0] * 256 * 256 + color_c[1] * 256 + color_c[2];
    map_info->color_f = color_f[0] * 256 * 256 + color_f[1] * 256 + color_f[2];
}

int count_splited(char **str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

void parse_color(t_map_size *map_info)
{
    int i;
    int j;
    int counted;

    i = 0;
    j = 1;
    int *colors_c;
    int *colors_f;
    char **splitted;
    colors_f = malloc(sizeof(int) * 3); 
    colors_c = malloc(sizeof(int) * 3); 
    counted = 0;
    while (map_info->map_content[i])
    {
        if (ft_strncmp(map_info->map_content[i],"F",1) == 0)
        {
            while (map_info->map_content[i][j] == ' ')
                j++;
            splitted = ft_split(map_info->map_content[i] + j, ',');
            if (count_splited(splitted) == 3)
            {
            colors_f[0] = ft_atoi(splitted[0]);
            colors_f[1] = ft_atoi(splitted[1]);
            colors_f[2] = ft_atoi(splitted[2]);

            }
            else{
                write(2,"wrong , only 3 args needed\n",28);
                free(splitted);
                exit (1);
            }
            free(splitted);
            counted++;
        }
        else if (ft_strncmp(map_info->map_content[i],"C",1) == 0)
        {
            while (map_info->map_content[i][j] == ' ')
                j++;
            splitted = ft_split(map_info->map_content[i] + j, ',');
            if (count_splited(splitted) == 3)
            {
            colors_c[0] = ft_atoi(splitted[0]);
            colors_c[1] = ft_atoi(splitted[1]);
            colors_c[2] = ft_atoi(splitted[2]);
            }
            else{
                write(2,"wrong , only 3 args needed\n",28);
                free(splitted);
                exit (1);
            }
            free(splitted);
            counted++;
        }
        i++;
    }
    if (counted != 2)
    {
        write(2,"wrong color format\n",20);
        exit(1);
    }
    parse_color2(map_info, colors_c, colors_f);
}