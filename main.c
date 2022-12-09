#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);

	for (int i = 0; i < 5; i++)
	{
		printf("%s", get_next_line(fd1));
		printf("%s", get_next_line(fd2));
	}
	printf("%s", get_next_line(0));
	close(fd1);
	close(fd2);
}
