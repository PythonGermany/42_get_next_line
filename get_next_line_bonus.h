/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:32:40 by rburgsta          #+#    #+#             */
/*   Updated: 2022/11/17 21:32:40 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>

char	*get_next_line(int fd);
void	read_data(int fd, char **line, char **stash);
int		split_data(char **line, char **src_data, char **dst_data);
int		ft_cpappend(char **dst, char *src, int line_break);
int		ft_strlen(char *str, int line_break);
void	*ft_calloc(size_t count, size_t size);

int ft_test(char **stash);

#endif