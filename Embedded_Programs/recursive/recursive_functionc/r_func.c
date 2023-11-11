#include<stdio.h>
int g=0;
char *reverse_str(char *cptr);
int main()
{
	char str[10];
	scanf("%s",str);
	int l,g;
	l=strlen(str);
	reverse_str(str);
}
char *reverse_str(char cptr[])
{

	printf("THE strings are\n");
	if(cptr[g]=='\0')
	return '\0';
	cptr[g]=cptr[g]+reverse_str(cptr++);
	return cptr;
}
	 


