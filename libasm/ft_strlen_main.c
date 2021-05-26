#include <stdio.h>

extern int ft_strlen(char *s);

int main(void)
{
	int result;

	result = ft_strlen("Hello World");
	printf("%d\n", result);
	return (0);
}
