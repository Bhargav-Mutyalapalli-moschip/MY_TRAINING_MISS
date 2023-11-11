#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	scanf("%s",str);
	char *p;
	p=strchr(str,'a');
	printf("%s\n",p);
	p=strrchr(str,'b');
	printf("%s\n",p);
}
