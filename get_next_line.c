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
#include <unistd.h>

char	*get_next_line(int fd)
{
	int			ret;
	char		*buffer;
	static char	*stash;
	char		*line;

	line = 0;
	if (stash)
		if (!ft_split_data(&line, &stash, &stash))
			return (line);
	if (!stash)
	{
		buffer = (char *)ft_calloc(1, BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		ret = read(fd, buffer, BUFFER_SIZE);
		while (ret > 0)
		{
			buffer[ret] = 0;
			if (!ft_split_data(&line, &buffer, &stash))
				break ;
			ret = read(fd, buffer, BUFFER_SIZE);
		}
		if (buffer && ret == 0)
			free(buffer);
	}
	return (line);
}

int	ft_split_data(char **line, char **src_data, char **dst_data)
{
	char	*buf;

	if (ft_strlen(*src_data, 0) == ft_strlen(*src_data, 1))
	{
		ft_cpappend(line, *src_data, 0);
		if (*dst_data)
			free(*dst_data);
		*dst_data = 0;
		if (line[0][ft_strlen(*line, 0) - 1] == '\n')
		{
			if (*src_data)
				free(*src_data);
			return (0);
		}
		return (1);
	}
	buf = 0;
	ft_cpappend(&buf, *src_data + ft_strlen(*src_data, 1), 0);
	ft_cpappend(line, *src_data, 1);
	free(*src_data);
	*dst_data = buf;
	return (0);
}

void	ft_cpappend(char **dst, char *src, int line_break)
{
	int		i;
	char	*buf;

	i = ft_strlen(*dst, line_break) + ft_strlen(src, line_break);
	buf = (char *)ft_calloc(1, i + 1);
	while (i-- > ft_strlen(*dst, line_break))
		buf[i] = src[i - ft_strlen(*dst, line_break)];
	i = ft_strlen(*dst, line_break);
	while (i-- > 0)
		buf[i] = dst[0][i];
	if (*dst)
		free(*dst);
	*dst = buf;
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
