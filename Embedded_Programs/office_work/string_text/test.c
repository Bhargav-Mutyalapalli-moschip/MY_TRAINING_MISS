#include<stdio.h>
#include<string.h>
int main()
{
	char str[3]="hello";
	char str1[5]="bye";
	char str2[20];
	printf("%d-----%d\n",sizeof(str),sizeof(str1));
	strcpy(str2,str);
	strcpy(str,str1);
	strcpy(str1,str2);
	printf("%s--------%s\n",str,str1);

}

