#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
void nonrepeat_substring(char *str);
int main()
{
	char str[100];
	printf("enter the string:");
	scanf("%s",str);
	__fpurge(stdin);
	nonrepeat_substring(str);
}
void nonrepeat_substring(char *str)
{
	char c;
	int i,j,ind1=0,ind2=0,k;
	int count1=0,count=1;
	for(i=0;str[i]!='\0';i++)
	{
		count=1;
		for(j=i+1;str[j]!='\0';j++)
		{
			if(str[i] != str[j])
			{
				count++;
			}
			else
			break;
		}
		printf("The count:%d\n",count);
		if(count > count1)
		{
			ind1=i;
			ind2=j;
			count1=count;
		}
		//c=str[i];
	}
	for(k=ind1;k<=ind2;k++)
	{
		printf("%c",str[k]);
	}
	printf("The count:%d\n",count1);
}






