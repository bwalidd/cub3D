/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:48:43 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/19 01:31:23 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include <stdlib.h>
# include "get_next_line/get_next_line.h"


# define KEY_W 'w'
# define KEY_S 's'
# define KEY_A 'a'
# define KEY_D 'd'
# define KEY_DOWN  65364
# define KEY_LEFT  65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_ESC 53
#define WIN_WIDTH 1000
#define WIN_HEIGHT 700
#define TILE_SIZE 50
#define FOV_ANGLE 60
#define PLAYER_SPEED 10.0

# define NUM_RAYS WINDOW_WIDTH

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map_size
{
    char **map;
    char **map_content;
    char *no_texture;
    char *so_texture;
    char *we_texture;
    char *ea_texture;
    int color_c;
    int map_height;
    int color_f;
    int map_width;
    int num_of_lines;
    int len_of_line;
    int number_horizontal;    
} t_map_size;

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;
    int bits_per_pixel;
    int size_line;
    int endian;
} t_mlx;

typedef struct s_player {
    int   x ;
    int   y ;
    int      dir;
    float    pixel_x;
    float    pixel_y;
    double   angle;
} t_player;

typedef struct s_vars {
    t_data *data;
    t_map_size *map;
    t_mlx *mlx;
    t_player *player;
} t_vars;

void raycasting(t_vars *vars);
void init_window(t_mlx *g_mlx,t_map_size *map_info, t_data *data);
void draw_mlx_map( t_vars *vars ,t_mlx *g_mlx, t_map_size *map_info);
void init_player(t_player *player, t_map_size *infos, t_mlx *g_mlx);
void init_player_pos(char **map, t_player *player, t_mlx *g_mlx, t_map_size *infos);
void draw_player(t_mlx *g_mlx, t_player *player);
void update_player(t_mlx *g_mlx, t_player *player);
int key_press_hook(int keycode, t_vars *vars);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void draw_rect(t_mlx *g_mlx, int x, int y, int width, int height, int color);
int get_file_extension(char *str);
int parsing(char *str,t_map_size *map_info);
void parse_texture(t_map_size *map_info,int *i);
void parse_color(t_map_size *map_info);
void get_map_textures(t_map_size *map_info);
void get_map(t_map_size *map_info);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_strcmp(char *s1, char *s2);
int	ft_isdigit(int c);
void check_map_cadre(t_map_size *map_info);
char *ft_strndup(char *s1, int n);
void check_map(t_map_size *map_info);
//void	*ft_calloc(size_t count, size_t size);
int check_chars(char c);
int check_wall_expanded(char **map,int j);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif