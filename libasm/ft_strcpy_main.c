#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *ft_strcpy(char *dst, const char *src);

int main(void)
{
	char *dst;
	char *src = "Hello World";

	dst = (char*)malloc(strlen(src));
//	strcpy(dst, src);
	ft_strcpy(dst, src);
	printf("%s\n", dst);
}
