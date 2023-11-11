#include<stdio.h>
int main()
{
	char plk[20];
	scanf("%s",plk);
	char *lku;
	lku=strpbrk(plk,"s");
	printf("%s",lku);
}

