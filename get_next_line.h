/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:34:19 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/24 22:34:19 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <stddef.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int	ft_split_data(char **line, char **src_data, char **dst_data);
int ft_strlen_gnl(char *str, int line_break);
void ft_append_gnl(char **dst, char *src, int line_break);
void	*ft_calloc(size_t count, size_t size);

int *get_allocated();
void ft_free(void *ptr);

#endif