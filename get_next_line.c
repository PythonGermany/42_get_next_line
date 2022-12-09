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

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		ret;
	static char *stash;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (0);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 1)
		return (0);
	while (ret > 0)
	{
		stash = append_buffer(stash, buffer, ret);
		if (contains_char(stash, '\n') != -1)
		{
			line = ft_substr(stash, 0, contains_char(stash, '\n'));
			stash += contains_char(stash, '\n');
			break ;
		}
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line);
}
