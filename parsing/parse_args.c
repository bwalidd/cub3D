/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 01:27:01 by wbouwach          #+#    #+#             */
/*   Updated: 2023/10/19 02:24:58 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int ft_strcmpp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    return 1;
}

int is_valid(char *str)
{
    int fd;

    fd = open(str,O_RDONLY);
    if (fd == -1)
    {
        write(2,"file not found\n",15);
        return 0;
    }
    close(fd);
    return 1;
}

int get_file_extension(char *str)
{
    int i = 0;
    int index_to_start;

    while(str[i])
        i++;
    index_to_start = i - 4;
    if (ft_strcmpp(str + index_to_start, ".cub"))
    {
        if (is_valid(str))
            return 0;
    }
    else
        write(2,"wrong file extension\n",22);
    return 1;
}
