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
	//char		*buffer;
	static char	*stash;
	char		*line;

	line = 0;

	if (!stash)
	{
		stash = (char *)malloc(BUFFER_SIZE + 1);
		stash[BUFFER_SIZE] = 0;
		ret = read(fd, stash, BUFFER_SIZE);
	}
	//printf("'%s'\n", stash);
	if (stash)
		if (!ft_split_stash(&line, &stash, &stash))
			return (line);
	// if (!stash)
	// {
	// 	buffer = (char *)malloc(BUFFER_SIZE + 1);
	// 	if (!buffer)
	// 		return (0);
	// 	buffer[BUFFER_SIZE] = 0;
	// 	ret = read(fd, buffer, BUFFER_SIZE);
	// 	while (ret > 0)
	// 	{
	// 		ft_append_gnl(&line, buffer, 1);
	// 		ft_split_stash(&line, &buffer, &stash);
	// 		ret = read(fd, buffer, BUFFER_SIZE);
	// 	}
	// 	free(buffer);
	// }
	return (line);
}

//Checked==seems to work
void ft_append_gnl(char **dst, char *src, int line_break)
{
	int	i;
	char *buf;

	i = ft_strlen_gnl(*dst, line_break) + ft_strlen_gnl(src, line_break);
	//printf("%i %i %i\n", i, ft_strlen_gnl(*dst, line_break), ft_strlen_gnl(src, line_break));
	buf = (char *)malloc(i + 1);
	buf[i] = 0;
	while (i-- > ft_strlen_gnl(*dst, line_break))
		buf[i] = src[i - ft_strlen_gnl(*dst, line_break)];
	i = ft_strlen_gnl(*dst, line_break);
	while (i-- > 0)
		buf[i] = dst[0][i];
	free(*dst);
	*dst = buf;
}

int	ft_split_stash(char **line, char **src_stash, char **dst_stash)
{
	int		i;
	char	*buf;

	if (ft_strlen_gnl(*src_stash, 0) == ft_strlen_gnl(*src_stash, 1))
	{
		ft_append_gnl(line, *src_stash, 0);
		*dst_stash = 0;
		return (1);
	}
	i = ft_strlen_gnl(*src_stash, 0);
	if (!*line)
		*line = (char *)malloc(ft_strlen_gnl(*src_stash, 1) + 1);
	buf = (char *)malloc(i - ft_strlen_gnl(*src_stash, 1) + 1);
	if (!*line || !buf)
		*line = 0;
	else
	{
		line[0][ft_strlen_gnl(*src_stash, 1)] = 0;
		buf[i - ft_strlen_gnl(*src_stash, 1)] = 0;
		//ft_append_gnl(&buf, *src_stash + ft_strlen_gnl(*src_stash, 1), 0);
		while (i-- > ft_strlen_gnl(*src_stash, 1)) 
			buf[i - ft_strlen_gnl(*src_stash, 1)] = src_stash[0][i];
		i = ft_strlen_gnl(*src_stash, 1);
		//ft_append_gnl(line, *src_stash, 1);
		while (i-- > 0) 
			line[0][i] = src_stash[0][i];
		free(*src_stash);
		*dst_stash = buf;
	}
	return (0);
}

int ft_strlen_gnl(char *str, int line_break)
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
