#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

extern ssize_t ft_read(int fildes, void *buf, size_t nbyte);

int main(void)
{
	char *buf = malloc(12);
	char *buf_2 = malloc(12);
	int fd;
	int fd2;

	fd = open("hello_world.txt", O_RDONLY);
	fd2 = open("hello_world.txt", O_RDONLY);
	printf("%ld\n", ft_read(fd, buf, 12));
	printf("%s\n", buf);
	printf("%ld\n", read(fd2, buf_2, 12));
	printf("%s\n", buf_2);
}
