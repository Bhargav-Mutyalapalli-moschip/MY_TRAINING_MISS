#include<stdio.h>
int main()
{
	char str1[200],str2[20];
	scanf("%s %s",str1,str2);
	strcat(str1,str2);
	printf("%s---------\n",str1);
	char str3[20];
	scanf("%s",str3);
	strcat(str1,str3);
	printf("---------------%s\n",str1);
}
