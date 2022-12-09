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

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	line = 0;
	if (stash[fd] && fd >= 0 && BUFFER_SIZE > 0)
		if (!split_data(&line, &stash[fd], &stash[fd]))
			return (line);
	if (!stash[fd] && fd >= 0 && BUFFER_SIZE > 0)
		read_data(fd, &line, &stash[fd]);
	return (line);
}

void	read_data(int fd, char **line, char **stash)
{
	int		ret;
	char	*buffer;

	buffer = (char *)ft_calloc(1, BUFFER_SIZE + 1);
	if (!buffer)
	{
		*line = 0;
		return ;
	}
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = 0;
		if (!split_data(line, &buffer, stash))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (buffer && ret < 1)
		free(buffer);
	if (*line && ret == -1)
	{
		free(*line);
		*line = 0;
	}
}

int	split_data(char **line, char **src_data, char **dst_data)
{
	char	*buf;

	if (ft_strlen(*src_data, 0) == ft_strlen(*src_data, 1))
	{
		ft_cpappend(line, *src_data, 0);
		if (*dst_data)
			free(*dst_data);
		*dst_data = 0;
		if (line[0][ft_strlen(*line, 0) - 1] == '\n' || !line)
		{
			if (*src_data)
				free(*src_data);
			return (0);
		}
		return (1);
	}
	buf = 0;
	if (!ft_cpappend(line, *src_data, 1))
		if (ft_cpappend(&buf, *src_data + ft_strlen(*src_data, 1), 0))
			*line = 0;
	free(*src_data);
	*dst_data = buf;
	return (0);
}

int	ft_cpappend(char **dst, char *src, int line_break)
{
	int		i;
	char	*buf;

	i = ft_strlen(*dst, line_break) + ft_strlen(src, line_break);
	buf = (char *)ft_calloc(1, i + 1);
	if (!buf)
	{
		if (*dst)
			free(*dst);
		*dst = 0;
		return (1);
	}
	while (i-- > ft_strlen(*dst, line_break))
		buf[i] = src[i - ft_strlen(*dst, line_break)];
	i = ft_strlen(*dst, line_break);
	while (i-- > 0)
		buf[i] = dst[0][i];
	if (*dst)
		free(*dst);
	*dst = buf;
	return (0);
}

int	ft_strlen(char *str, int line_break)
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
