/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:34:16 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/24 22:34:16 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

char	*get_next_line(int fd)
{
	int			ret;
	char		*buffer;
	static char	*stash;
	char		*line;

	line = 0;
	if (stash)
		if (!ft_split_stash(&line, &stash, &stash))
			return (line);
	if (!stash)
	{
		buffer = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		ret = read(fd, buffer, BUFFER_SIZE);
		while (ret > 0)
		{
			if (!ft_split_stash(&line, &buffer, &stash))
				break ;
			ret = read(fd, buffer, BUFFER_SIZE);
		}
	}
	return (line);
}

void	ft_append_gnl(char **dst, char *src, int line_break)
{
	int		i;
	char	*buf;

	i = ft_strlen_gnl(*dst, line_break) + ft_strlen_gnl(src, line_break);
	buf = (char *)ft_calloc(1, i + 1);
	while (i-- > ft_strlen_gnl(*dst, line_break))
		buf[i] = src[i - ft_strlen_gnl(*dst, line_break)];
	i = ft_strlen_gnl(*dst, line_break);
	while (i-- > 0)
		buf[i] = dst[0][i];
	free(*dst);
	*dst = buf;
}

int	ft_split_stash(char **line, char **src_data, char **dst_data)
{
	int		i;
	char	*buf;

	if (ft_strlen_gnl(*src_data, 0) == ft_strlen_gnl(*src_data, 1))
	{
		ft_append_gnl(line, *src_data, 0);
		if (*dst_data)
			free(*dst_data);
		//printf("line :%s\n", *line);
		*dst_data = 0;
		return (1);
	}
	i = ft_strlen_gnl(*src_data, 0);
	if (!*line)
		*line = (char *)ft_calloc(1, ft_strlen_gnl(*src_data, 1) + 1);
	buf = (char *)ft_calloc(1, i - ft_strlen_gnl(*src_data, 1) + 1);
	if (!*line || !buf)
		*line = 0;
	else
	{
		ft_append_gnl(&buf, *src_data + ft_strlen_gnl(*src_data, 1), 0);
		//printf("src_data :%s\n", *src_data + ft_strlen_gnl(*src_data, 1));
		ft_append_gnl(line, *src_data, 1);
		free(*src_data);
		*dst_data = buf;
	}
	return (0);
}

int	ft_strlen_gnl(char *str, int line_break)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && (str[i] != '\n' || !line_break))
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
