/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:30:48 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/22 01:50:13 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while ((s1[a] || s2[a]) && a < n)
	{
		if (s1[a] == s2[a])
			a++;
		else
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}
