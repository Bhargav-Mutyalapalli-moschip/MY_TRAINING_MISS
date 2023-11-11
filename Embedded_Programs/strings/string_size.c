#include<stdio.h>
int main()
{
	char str1[15]="ram";
	printf("size of str1:%d\n",sizeof(str1));
	printf("size of str1:%d\n",strlen(str1));
	char str2[10]="bro";
	strcpy(str1+strlen(str1)+1,str2);
        str1[strlen(str1)]=' ';
	printf("%s---------------%s\n",str1,str2);
	char str3[10];
	str3="bhargav";
	printf("The directly assigned:%s\n",str3);
}
