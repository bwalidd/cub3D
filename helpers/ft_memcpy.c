/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:19:08 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/22 02:05:07 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	if (dst == src || !n)
		return (dst);
	index = 0;
	while (index < n)
	{
		*((char *) dst + index) = *((char *)src + index);
		index++;
	}
	return (dst);
}
