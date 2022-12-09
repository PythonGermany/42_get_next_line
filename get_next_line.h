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
#  define BUFFER_SIZE 10
# endif

#include <stdlib.h>

char	*get_next_line(int fd);
int		ft_split_data(char **line, char **src_data, char **dst_data);
void	ft_cpappend(char **dst, char *src, int line_break);
int		ft_strlen(char *str, int line_break);
void	*ft_calloc(size_t count, size_t size);

#endif