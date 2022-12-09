#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	// int fd1 = open("test1.txt", O_RDONLY);
	// char *str = (char *)1;
	// while (str)
	// {
	// 	str = get_next_line(fd1);
	// 	printf("%i %s", i, str);
	// 	free(str);
	// }
	// close(fd1);

	int i = 0;
	char *str = (char *)1;
	while (str)
	{
		str = get_next_line(0);
		printf("%i %s", i++, str);
		free(str);
	}

	//system("leaks a.out");
	return (0);
}
