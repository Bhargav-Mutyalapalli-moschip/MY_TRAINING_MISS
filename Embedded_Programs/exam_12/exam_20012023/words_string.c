#include<stdio.h>
#include<string.h>
int chr_max(char*str)
{
	int i,j,count1=0,count2=0;
	j=strlen(str);
	for(i=0;i<=j;i++)
	{
		if(str[i]==' '||str[i]=='\0')
		{
			count1++;
		}
	}
	return (count1);
}
int main()
{
	char str[100],letter;
	int res;
	printf("enter the statement : ");
	scanf("%[^\n]s",str);
	res=chr_max(str);
	printf("no of words : %d \n",res);
}

