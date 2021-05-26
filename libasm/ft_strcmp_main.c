#include <stdio.h>
#include <string.h>

extern int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	char *s1 = "Hello";
	char *s2 = "Hello W";

	printf("%d\n", ft_strcmp(s1, s2));
}
