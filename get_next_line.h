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

char	*get_next_line(int fd);
int	ft_split_stash(char **line, char **src_stash, char **dst_stash);
int ft_strlen_gnl(char *str, int line_break);
void ft_append_gnl(char **dst, char *src, int line_break);

#endif