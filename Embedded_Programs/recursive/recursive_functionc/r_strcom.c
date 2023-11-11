#include<stdio.h>
#include<stdio_ext.h>
int i=0;
char* stringcopy(char *str,char *str1,int k);
int main()
{
	char str[20];
	char str1[20];
	int res;
	printf("Enter the string to check the string length\n");
	scanf("%s",str);
	__fpurge(stdin);
	//scanf("%s",str1);
	stringcopy(str,str1,i);
	printf("%s",str1);
}
char* stringcopy(char *str,char *str1,int k)
{
	if(str[k]!='\0')
	{
		str1[k]=str[k];
		stringcopy(str,str1,k=k+1);

		
	}
	return str1;
}
