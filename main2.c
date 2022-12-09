/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburgsta <rburgsta@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:36:28 by rburgsta          #+#    #+#             */
/*   Updated: 2022/10/27 12:36:28 by rburgsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int fd = open("test1.txt", O_RDONLY);
	char *str = (char *)1;
	//printf("fd: %i\n", fd);
	while (str)
	{
		str = get_next_line(fd);
		printf("%i|%s", i++, str);
		free(str);
	}
	close(fd);
	//printf("end allocated: %i\n", *get_allocated());
	//system("leaks a.out");
	return (0);
}
