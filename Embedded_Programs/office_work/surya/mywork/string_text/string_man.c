#include<stdio.h>
int main()
{
	char str1[120]="nagar";
	char str2[20]="ram";
	//printf("%p\n",(str1+4));
	strcpy(str1+strlen(str1),str2);
	//printf(str1);
	//func(str1);
}
void func(char str[])
{
	str=str+1;
	char str2[10];
	str2=str2+2;
	printf(str);
	printf("\n");
}
