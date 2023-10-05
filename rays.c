/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 00:30:24 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/02 01:03:51 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void cast_ray(float ray_angle, t_player *player)
{
    
}

void cast_rays(t_player *player)
{
    float ray_angle;
    int i;

    ray_angle = player->rotation_angle - (FOV_ANGLE / 2);
    i = 0;
    while (i < player->num_rays)
    {
        cast_ray(ray_angle, player);
        ray_angle += FOV_ANGLE / player->num_rays;
        i++;
    }    
}