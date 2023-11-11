#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	printf("enter a string:");
	scanf("%[^\n]",str);
	int i,j,count;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		str[i]=str[i]-32;
		else if(str[i] >= 'A' && str[i] <= 'Z')
		str[i]=str[i]+32;
	}
	printf("The changed font:%s\n",str);
}



