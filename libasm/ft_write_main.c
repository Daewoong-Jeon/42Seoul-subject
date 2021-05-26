#include <unistd.h>
#include <stdio.h>

extern ssize_t ft_write(int fildes, const void *buf, size_t nbyte);

int main(void)
{
	char *s = "Hello World\n";

	ft_write(1, s, 12);
//	write(1, s, 12);
}
