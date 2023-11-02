/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:35:06 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/31 16:35:06 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_file_to_img(t_vars *vars)
{
	int	height;
	int	width;

	vars->mlx->n_xpm = mlx_xpm_file_to_image(vars->mlx->mlx_ptr,
			vars->mlx->north_img, &width, &height);
	vars->mlx->s_xpm = mlx_xpm_file_to_image(vars->mlx->mlx_ptr,
			vars->mlx->south_img, &width, &height);
	vars->mlx->e_xpm = mlx_xpm_file_to_image(vars->mlx->mlx_ptr,
			vars->mlx->east_img, &width, &height);
	vars->mlx->w_xpm = mlx_xpm_file_to_image(vars->mlx->mlx_ptr,
			vars->mlx->west_img, &width, &height);
}

void	get_data_addr(t_vars *vars)
{
	vars->mlx->addr_n = mlx_get_data_addr(vars->mlx->n_xpm, &vars->mlx->bpp_n,
			&vars->mlx->l_len_n, &vars->mlx->endian_n);
	vars->mlx->addr_s = mlx_get_data_addr(vars->mlx->s_xpm, &vars->mlx->bpp_s,
			&vars->mlx->l_len_s, &vars->mlx->endian_s);
	vars->mlx->addr_w = mlx_get_data_addr(vars->mlx->w_xpm, &vars->mlx->bpp_w,
			&vars->mlx->l_len_w, &vars->mlx->endian_w);
	vars->mlx->addr_e = mlx_get_data_addr(vars->mlx->e_xpm, &vars->mlx->bpp_e,
			&vars->mlx->l_len_e, &vars->mlx->endian_e);
}


void	img_to_xpm(t_vars *vars)
{
	vars->mlx->north_img = vars->map->no_texture;
	vars->mlx->south_img = vars->map->so_texture;
	vars->mlx->east_img = vars->map->ea_texture;
	vars->mlx->west_img = vars->map->we_texture;
	xpm_file_to_img(vars);
	if (!vars->mlx->n_xpm || !vars->mlx->s_xpm
		|| !vars->mlx->w_xpm || !vars->mlx->e_xpm)
	{
		printf("Error Loading Textures\n");
		exit(0);
	}
	get_data_addr(vars);
}

char	*north_textures(t_vars *vars, int i)
{
	int	x;
	int	y;

	x = (int)round(vars->player->where);
	if (vars->mlx->wall_height > WIN_HEIGHT)
		y = (int)(round)((i + (vars->mlx->wall_height - WIN_HEIGHT) / 2.0)
				* (1000.0 / vars->mlx->wall_height)) % 1000;
	else
		y = (int)round(i * (1000.0 / vars->mlx->wall_height)) % 1000;
	vars->mlx->color = vars->mlx->addr_n + (y * vars->mlx->l_len_n + (x * 4));
	return (vars->mlx->color);
}

// char *south_textures(t_vars *vars, int i)
// {
//     int x;
//     int y;

//     x = (int)round(vars->player->where);
//     if (vars->mlx->corrected_distance > WIN_HEIGHT)
//         y = (int)(round)((i + (vars->mlx->corrected_distance - WIN_HEIGHT) / 2.0) * (1000.0 / vars->mlx->corrected_distance)) % 1000;   
//     else
//         y = (int)(round)((i + (WIN_HEIGHT - vars->mlx->corrected_distance) / 2.0) * (1000.0 / vars->mlx->corrected_distance)) % 1000;
//     vars->mlx->color = vars->mlx->addr_s + (y * vars->mlx->l_len_s + x * (vars->mlx->bpp_s / 8));
//     return (vars->mlx->color);
// }

// char *west_textures(t_vars *vars, int i)
// {
//     int x;
//     int y;

//     x = (int)round(vars->player->where);
//     if (vars->mlx->corrected_distance > WIN_HEIGHT)
//         y = (int)(round)((i + (vars->mlx->corrected_distance - WIN_HEIGHT) / 2.0) * (1000.0 / vars->mlx->corrected_distance)) % 1000;   
//     else
//         y = (int)(round)((i + (WIN_HEIGHT - vars->mlx->corrected_distance) / 2.0) * (1000.0 / vars->mlx->corrected_distance)) % 1000;
//     vars->mlx->color = vars->mlx->addr_w + (y * vars->mlx->l_len_w + x * (vars->mlx->bpp_w / 8));
//     return (vars->mlx->color);
// }

// char *east_textures(t_vars *vars, int i)
// {
//     int x;
//     int y;

//     x = (int)round(vars->player->where);
//     if (vars->mlx->corrected_distance > WIN_HEIGHT)
//         y = (int)(round)((i + (vars->mlx->corrected_distance - WIN_HEIGHT) / 2.0) * (1000.0 / vars->mlx->corrected_distance)) % 1000;   
//     else
//         y = (int)(round)((i + (WIN_HEIGHT - vars->mlx->corrected_distance) / 2.0) * (1000.0 / vars->mlx->corrected_distance)) % 1000;
//     vars->mlx->color = vars->mlx->addr_e + (y * vars->mlx->l_len_e + x * (vars->mlx->bpp_e / 8));
//     return (vars->mlx->color);
// }