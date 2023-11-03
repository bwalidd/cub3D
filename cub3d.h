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

# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# define KEY_W 'w'
# define KEY_S 's'
# define KEY_A 'a'
# define KEY_D 'd'
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_ESC 53
# define WIN_WIDTH 1000
# define WIN_HEIGHT 700
# define TILE_SIZE 50
# define FOV_ANGLE 60
# define PLAYER_SPEED 10.0
# define WALL_DISTANCE_THRESHOLD 10.0
# define NUM_RAYS WINDOW_WIDTH

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map_size
{
	int		color_c;
	int		map_height;
	int		color_f;
	int		map_width;
	int		num_of_lines;
	int		len_of_line;
	int		number_horizontal;
	char	**map;
	char	**map_content;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
}	t_map_size;

typedef struct s_mlx
{
	void	*mlx_ptrs;
	void	*win_ptrs;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*north_img;
	char	*south_img;
	char	*east_img;
	char	*west_img;
	char	*n_xpm;
	char	*s_xpm;
	char	*e_xpm;
	char	*w_xpm;
	int		bits_per_pixel;
	int		size_line;

	int		bpp_n;
	int		l_len_n;
	int		endian_n;

	int		bpp_s;
	int		l_len_s;
	int		endian_s;

	int		bpp_w;
	int		l_len_w;
	int		endian_w;

	int		bpp_e;
	int		l_len_e;
	int		endian_e;

	char	*addr_n;
	char	*addr_s;
	char	*addr_w;
	char	*addr_e;
	char	*color;
	double	corrected_distance;
	double	wall_height;
	int		endian;
	int		col;
}	t_mlx;

typedef struct s_player
{
	int		x_m;
	int		y_m;
	double	distance;
	char	dir;
	int		x;
	int		y;
	int		x_step;
	int		y_step;
	double	where;
	float	pixel_x;
	float	pixel_y;
	double	angle;
	int		move_forward;
	int		move_backward;
	int		turn_left;
	int		turn_right;
	int		slide_r;
	int		slide_l;
	int		x_mouse;
	int		y_mouse;
}	t_player;

typedef struct s_vars
{
	double		player_x;
	double		player_y;
	double		delta_x;
	double		delta_y;
	double		ray_x;
	double		ray_y;
	double		ray_angle;
	int			x;
	double		new_x;
	double		new_y;
	int			map_x;
	int			map_y;
	t_data		*data;
	t_map_size	*map;
	t_mlx		*mlx;
	t_player	*player;
}		t_vars;

void	raycasting(t_vars *vars);
void	init_window(t_mlx *g_mlx, t_data *data);
void	draw_mlx_map(t_vars *vars, t_mlx *g_mlx, t_map_size *map_info);
void	init_player(t_player *player, t_map_size *infos, t_mlx *g_mlx);
void	init_player_pos(char **map, t_player *player, t_vars *vars);
void	draw_player(t_mlx *g_mlx, t_player *player);
void	update_player(t_mlx *g_mlx, t_player *player);
int		moving(t_vars *vars);
void	fill_vars(int *i, int *j, int *counted);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_rect(t_mlx *g_mlx, int x, int y, int width);
int		get_file_extension(char *str);
void	fill_map(int count, t_map_size *map_info, int i, int j);
int		parsing(char *str, t_map_size *map_info);
void	parse_texture(t_map_size *map_info, int *i);
void	parse_color(t_map_size *map_info);
void	get_map_textures(t_map_size *map_info);
void	get_map(t_map_size *map_info);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		get_num_of_lines(char **content);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
void	check_map_cadre(t_map_size *map_info);
char	*ft_strndup(char *s1, int n);
void	check_map(t_map_size *map_info);
int		check_chars(char c);
int		check_wall_expanded(char **map, int j);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	img_to_xpm(t_vars *vars);
char	*north_textures(t_vars *vars, int i);
void	check_is_zero_surrounded(t_map_size *map_info);
char	*south_textures(t_vars *vars, int i);
char	*west_textures(t_vars *vars, int i);
void	check_inside_map(t_map_size *map_info, int i);
char	*east_textures(t_vars *vars, int i);
int		check_corners(t_map_size *map_info, int i, int j);
void	display_image(t_vars *vars); // remove
void	check_is_closed(char **map, int i);
void	ft_puterror(char *str);
void	check_is_surrounded_by_wall(char **map, int i);
void	go_ahead(t_vars *vars);
void	go_back(t_vars *vars);
void	slide_right(t_vars *vars);
void	slide_left(t_vars *vars);
void	draw_it(t_vars *vars);
void	wall_hit(t_vars *vars);
int		mouse_mv(int x, int y, t_vars *vars);
char	check_north_west(double w_y, double w_x, t_vars *vars);
char	check_north_east(double w_y, double w_x, t_vars *vars);
char	check_south_east(double w_y, double w_x, t_vars *vars);
char	check_south_west(double w_y, double w_x, t_vars *vars);
#endif
