/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:47:58 by wbouwach          #+#    #+#             */
/*   Updated: 2023/08/27 20:47:58 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


// split map using get_next_line
char **split_map(char *file)
{
    int fd;
    char *line;
    char **map;
    int i;

    i = 0;
    fd = open(file, O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
        i++;
        free(line);
    }
    close(fd);
    map = malloc(sizeof(char *) * (i + 1));
    fd = open(file, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        map[i] = ft_strdup(line);
        free(line);
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

int main(int ac, char **av)
{
  
    char **map;
    t_player *player;

    if (ac < 2)
        return (0);
    if (parse_map(av[1]) == 0)
        return (1);
    player = malloc(sizeof(t_player*));
    map = split_map(av[1]);
    init_player_pos(map, player);
    init_window();
    draw_mlx_map(map, g_mlx.win_ptr, g_mlx.mlx_ptr);
    return (0);
}