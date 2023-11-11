#include<stdio.h>
int main()
{
	int i=0;
	char str[20]="I am pranav i am going to rock";
	char str1[10]="pranav";
	char *str2;
	str2=strstr(str,str1);
	if(str2==NULL)
	{
		printf("String is not found\n");
		return;
	}
	else
	{
		while(str2[0]!=' ')
		{
			printf("%c",str2[i]);
			i++;
		}
	}
}
