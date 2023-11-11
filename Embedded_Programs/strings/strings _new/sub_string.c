#include<stdio.h>
int main()
{
	char str[50]="hellohii";
	char str1[10]="hii";
	char coun[10];
	coun=strstr(str,str1);
	if(coun!='\0')
		printf("String is not found\n");
	else
		printf("String is found\n");
}

