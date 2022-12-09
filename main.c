#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd1 = open("test1.txt", O_RDONLY);
	char *str = (char *)1;
	while (str)
	{
		str = get_next_line(fd1);
		printf("%s", str);
		free(str);
	}
	close(fd1);
	system("leaks a.out");
}
