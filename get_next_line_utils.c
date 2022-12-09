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

int allocated = 0;

int *get_allocated()
{
	return (&allocated);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (((count == (size_t)-1 && size) || (size == (size_t)-1 && count)))
		return (0);
	ptr = malloc(count * size);
	allocated++;
	if (ptr)
		while (i < count * size)
			*((unsigned char *)ptr + i++) = 0;
	return (ptr);
}

void ft_free(void *ptr)
{
	free(ptr);
	allocated--;
}