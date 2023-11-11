#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *ptr;
	ptr=(char *)malloc(10*sizeof(char));
	printf("%p\n",ptr);
	ptr = "surya";
	printf("%p\n",ptr);
}
