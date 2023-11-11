#include<stdio.h>
int i=0;
int count=0;
int stringlength(char *str,int k);
int main()
{
	char str[20];
	int res;
	printf("Enter the string to check the string length\n");
	scanf("%s",str);
	res=stringlength(str,i);
	printf("The string count is:%d\n",res);
}
int stringlength(char *str,int k)
{
	if(str[k]!='\0')
	{
		count++;
		stringlength(str,k=k+1);
	}
	return count;
}
