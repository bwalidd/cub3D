/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:58:12 by wbouwach          #+#    #+#             */
/*   Updated: 2022/11/08 17:21:10 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rest_of_line(char *buffer)
{
	int		i;
	char	*res;
	int		idx;

	idx = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!res)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i])
		res[idx++] = buffer[i++];
	res[idx] = 0;
	free(buffer);
	return (res);
}

char	*ft_read_line(char *buffer)
{
	char	*line;
	int		i;
	int		cmpt;

	i = 0;
	cmpt = 0;
	line = NULL;
	if (!(*buffer))
		return (NULL);
	while (buffer[cmpt] != '\0' && buffer[cmpt] != '\n')
		cmpt++;
	if (buffer[cmpt] == '\0')
		line = ft_calloc((cmpt + 1), sizeof(char));
	else if (buffer[cmpt] == '\n')
		line = ft_calloc((cmpt + 2), sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_read_buf(int fd, char *reserve)
{
	char	*buffer;
	int		cmpt;

	cmpt = 1;
	if (!reserve)
		reserve = ft_calloc(1, sizeof(char));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (cmpt > 0)
	{
		cmpt = read(fd, buffer, BUFFER_SIZE);
		if (cmpt == -1)
		{
			free(buffer);
			free(reserve);
			return (NULL);
		}
		buffer[cmpt] = 0;
		reserve = ft_strjoin(reserve, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_buf(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_read_line(buffer);
	buffer = rest_of_line(buffer);
	return (line);
}
