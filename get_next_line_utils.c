/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:34:14 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/24 22:34:14 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && i < start)
		i++;
	if (i < start)
		return (malloc(1));
	while (s[i] && i < start + len)
		i++;
	dest = (char *)malloc(i - start + 1);
	if (!dest)
		return (0);
	dest[i - start] = 0;
	while (i > start)
	{
		i--;
		dest[i - start] = s[i];
	}
	return (dest);
}

char	*append_buffer(char *str, char *buffer, int size)
{
	int		i;
	int		str_len;
	char	*out;

	i = 0;
	if (str)
		while (str[i])
			i++;
	out = malloc(i + size + 1);
	if (!out)
		return (0);
	str_len = i;
	while (i-- > 0)
		out[i] = str[i];
	out[str_len + size] = 0;
	while (size-- > 0)
		out[str_len + size] = buffer[size];
	return (out);
}
