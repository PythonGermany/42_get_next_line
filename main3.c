#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	// char *dst = malloc(10);
	// for (int i = 0; i < 3; i++)
	// 	dst[i] = '0';
	// char *src = ". And this is\n another test.";
	// printf("'%s'|'%s'\n", dst, src);
	// ft_append_gnl(&dst, src, 0);
	// printf("%s\n", dst);
	// for (int i = 0; i < 40; i++)
	// 	printf("%i ", dst[i]);

	// char *str;
	// str = get_next_line(0);
	// printf("'%s'", str);
	// free(str);
	// str = get_next_line(0);
	// printf("'%s'", str);
	// free(str);
	// str = get_next_line(0);
	// printf("'%s'", str);
	// free(str);

	//int i = 0;
	char *str = (char *)1;
	while (str)
	{
		str = get_next_line(0);
		//printf("%i|%s", i++, str);
		printf("%s", str);
		free(str);
	}
	//printf("end allocated: %i\n", *get_allocated());
	//system("leaks a.out");
	return (0);
}
