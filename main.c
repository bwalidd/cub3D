/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:47:58 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/19 01:45:06 by wbouwach         ###   ########.fr       */
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
    //printf("nbr_of_line is %d\n",nbr_of_line);
    close(fd);
    map = (char **)malloc((nbr_of_line + 1) * sizeof(char *));
    fd = open(file, O_RDONLY);
    i = 0;
    while (i < nbr_of_line)
    {
       map[i] = get_next_line(fd);
      // map[i][ft_strlen(map[i] - 1)] = '\0';
       //printf("from top => %s",map[i]);
       i++;
    }
    map[i] = NULL;
    close(fd);
    i = 0;
    //printf("===================\n");
    while (i < nbr_of_line)
    {
       //printf("from medium => %s",map[i]);
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
    map_info->number_horizontal = (int)ft_strlen(map_info->map[0]);
    map_info->number_horizontal--;
    //map_info->map_height = i * TILE_SIZE ;
    //map_info->map_width = map_info->number_horizontal * TILE_SIZE;
}

int custom_exit(void *param)
{
    t_mlx  *g_mlx = (t_mlx *)param;
    mlx_destroy_window(g_mlx->mlx_ptr, g_mlx->win_ptr);
    exit(0);
}

int main(int ac, char **av)
{
    t_map_size *map_info;
    t_player *player;
    t_mlx   *g_mlx;
    t_vars *vars;
    t_data *data;
    
    if (ac < 2)
        return (0);
    map_info = malloc(sizeof(t_map_size));
    if (parsing(av[1], map_info))
       return (1);
    //t_data *data;
    //data = malloc(sizeof(t_data));
    player = malloc(sizeof(t_player));
    vars = malloc(sizeof(t_vars));
    data = malloc(sizeof(t_data));
    vars->data = data;
    vars->player = player;
    vars->map = map_info;
    vars->player->angle = 0;
    fill_map_info(map_info,av);
    g_mlx = malloc(sizeof(t_mlx));
    vars->mlx = g_mlx;
    init_window(g_mlx,map_info,data);
    init_player_pos(map_info->map, player,g_mlx,map_info);
    draw_mlx_map(vars,g_mlx,map_info);
    mlx_hook(g_mlx->win_ptr, 2, 1L << 0, key_press_hook, vars);
    //draw_mlx_map(vars,g_mlx,map_info);
    //mlx_hook(g_mlx->win_ptr, 17, 1L << 17, custom_exit, vars);
     //mlx_put_image_to_window(vars->mlx->mlx_ptr,vars->mlx->win_ptr, vars->data->img, 0,0);
    mlx_loop(g_mlx->mlx_ptr);
    return (0);
}
