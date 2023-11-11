#include<stdio.h>
#include<string.h>
int main()
{
	char str1[10]="VAries";
	char str2[20]="ram";
	char str3[50];
	strcpy(str3,str1);
	printf("%s-----------%s\n",str1,str2);
	strcpy(str1,str2);
	printf("%s-----------%s\n",str1,str2);
	strcpy(str2,str3);
	printf("%s-----------%s\n",str1,str2);
}


