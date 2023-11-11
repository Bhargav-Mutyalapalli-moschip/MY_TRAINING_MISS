#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100];
	scanf("%[^\n]",str1);
	__fpurge(stdin);
	char str2[100];
	scanf("%[^\n]",str2);
	char temp;
	int count=0,i;
	temp=strstr(str1,str2);
	printf("The count:%d\n",count);
}

