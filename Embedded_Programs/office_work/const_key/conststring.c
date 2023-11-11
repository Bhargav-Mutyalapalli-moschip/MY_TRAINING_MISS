#include<stdio.h>
char* mystrincopy(const char*dst,char*src);
int main()
{
	char arr[100]="EXample weregyfjhefrvbfvur";
	char str[100]="huicegfc";
	mystrincopy(arr,str);
}
char *mystrincopy(const char*dst,char*src)
{
	int i;
	for(i=0;src[i]!='\0';i++)
	{
		dst[i]=src[i];
	}
	dst[i]='\0';
	return dst;
}


