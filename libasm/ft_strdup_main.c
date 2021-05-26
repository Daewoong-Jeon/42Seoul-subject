#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern char *ft_strdup(const char *s1);

int main(void)
{
	char *s = "Hello World";
	char *result1;
	char *result2;

	result1 = ft_strdup(s);
	result2 = strdup(s);
	printf("%s\n", result1);
	printf("%s\n", result2);
}
