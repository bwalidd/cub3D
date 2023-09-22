/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:47:58 by wbouwach          #+#    #+#             */
/*   Updated: 2023/09/17 11:54:24 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// split map using get_next_line
char **split_map(char *file)
{
    int fd;
    char **map;
    int nbr_of_line;
    int i;

    nbr_of_line = 0;
    fd = open(file, O_RDONLY);
    while (get_next_line(fd) != NULL)
        nbr_of_line++;
    printf("nbr_of_line is %d\n",nbr_of_line);
    close(fd);
    map = (char **)malloc((nbr_of_line + 1) * sizeof(char *));
    fd = open(file, O_RDONLY);
    i = 0;
    while (i < nbr_of_line)
    {
       map[i] = get_next_line(fd);
      // map[i][ft_strlen(map[i] - 1)] = '\0';
       printf("from top => %s",map[i]);
       i++;
    }
    map[i] = NULL;
    close(fd);
    i = 0;
    printf("===================\n");
    while (i < nbr_of_line)
    {
       printf("from medium => %s",map[i]);
       i++;
    }
    return (map);
}



void fill_map_info(t_map_size *map_info,char **av)
{
    int i = 0;
    map_info->map = split_map(av[1]);
    while (map_info->map[i])
        i++;
    map_info->num_of_lines = i;
    map_info->len_of_line = (int)ft_strlen(map_info->map[0]);
    map_info->len_of_line--;
}

int main(int ac, char **av)
{
  
    t_map_size *map_info;
    t_player *player;
    t_mlx   *g_mlx;
    
    if (ac < 2)
        return (0);
    //if (parse_map(av[1]) == 0)
      //  return (1);
    player = malloc(sizeof(t_player));
    map_info = malloc(sizeof(t_map_size));
    fill_map_info(map_info,av);
    g_mlx = malloc(sizeof(t_mlx));
    init_window(g_mlx,map_info);
    draw_mlx_map(map_info->map, g_mlx,map_info);
    init_player_pos(map_info->map, player,g_mlx,map_info);
    mlx_hook(g_mlx->win_ptr, 2, 1L << 0, key_press_hook, player);
    mlx_loop(g_mlx->mlx_ptr);
    return (0);
}
