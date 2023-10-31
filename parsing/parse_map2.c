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

int check_wall(char **map, int i, int j)
{
    while (map[i][j])
    {
        printf(" == %c ==\n",map[i][j]);
        if (map[i][j] != '1' && map[i][j] != ' ')
            return 0;  // If any non-'1' and non-space character is found, return 1 (invalid)
        j++;
    }
    return 1;  // If all characters in the row are '1' or spaces, return 0 (valid)
}


void ft_puterror(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1,&str[i++],1);
    }
    exit(1);
}

void check_is_surrounded_by_wall(char **map, int i)
{
    int j;

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

void check_is_closed(char **map, int i)
{
    int j;
    int len;
    
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
        printf(" - %d - %d\n",i ,len - 1);
        ft_puterror("invalid map (not end by one)\n");
    }
    
}

int check_corners(t_map_size *map_info, int i, int j)
{
    //printf("i == %d j == %d\n",i,j);
    if ((i > 0 && i < map_info->num_of_lines - 1))
    {
        if(j >= ft_strlen(map_info->map[i + 1]) || j >= ft_strlen(map_info->map[i - 1]))
        {
            printf("i = %d j = %d\n",i,j);
            printf("heeere 00\n");
            return (1);
        }
    }
    if (map_info->map[i + 1][j] == ' ')
    {
        printf("i = %d j = %d\n",i,j);
        printf("heeere 05\n");
        return (1);
    }
    if (map_info->map[i - 1][j] == ' ')
    {
        printf("i = %d j = %d\n",i,j);
        printf("heeere 03\n");
        return (1);
    }
    if (!map_info->map[i][j + 1] || map_info->map[i][j + 1] == ' ')
    {
        printf("i = %d j = %d\n",i,j);
        printf("heeere 02\n");
        return (1);
    }
    if (!map_info->map[i][j - 1] || map_info->map[i][j - 1] == ' ')
    {
        printf("i = %d j = %d\n",i,j);
        printf("heeere 01\n");
        return (1);
    }
    return (0);
}




void check_is_zero_surrounded(t_map_size *map_info)
{
    int i;
    int j;

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


void check_inside_map(t_map_size *map_info, int i)
{
    if (i > 0 && i < map_info->num_of_lines - 1)
        check_is_closed(map_info->map, i);
        
}


void check_map_cadre(t_map_size *map_info)
{
    int i = 1;
    check_is_surrounded_by_wall(map_info->map, 0);
    check_is_surrounded_by_wall(map_info->map,map_info->num_of_lines - 1);
    while (map_info->map[i])
    {
        check_inside_map(map_info ,i);
        i++;
    }
    check_is_zero_surrounded(map_info);
}

