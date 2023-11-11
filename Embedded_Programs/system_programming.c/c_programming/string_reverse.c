#include<stdio.h>
#include<string.h>
int main()
{
	char c;
	char str[50];
	printf("Enter the string\n");
	scanf("%s",str);
	int i,j;
	j=strlen(str);
	j=j-1;
	for(i=0;i<j;i++,j--)
	{
		c=str[i];
		str[i]=str[j];
		str[j]=c;
	}
	printf("The output string:%s\n",str);
}




