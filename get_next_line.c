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
	int		i;
	char	*out;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (0);
	i = 0;
	out = 0;
	while (read(fd, &buffer[i], 1) > 0 && buffer[i++] != '\n')
	{
		if (i == BUFFER_SIZE)
		{
			out = append_buffer(out, ft_substr(buffer, 0, i), i);
			i = 0;
		}
	}
	if (!i)
		return (0);
	out = append_buffer(out, ft_substr(buffer, 0, i), i);
	free(buffer);
	return (out);
}
