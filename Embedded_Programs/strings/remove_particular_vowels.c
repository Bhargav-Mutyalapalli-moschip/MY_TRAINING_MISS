#include<stdio.h>
#include<string.h>
int main()
{
	char chara;
	int i,j,k;
	char str[30];
	printf("enter the string:");
	scanf("%s",str);
	__fpurge(stdin);
	printf("enter the particular character to delete:");
	scanf("%c",&chara);
	__fpurge(stdin);
	for(i=0;str[i]!='\0';i++)
	{
		if('a' == str[i] || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
		{
			for(k=i;str[k]!='\0';k++)
			str[k]=str[k+1];
			i--;
		}
	}
	printf("the output string:%s\n",str);

}


