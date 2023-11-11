#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int i,j;
	printf("enter the string:");
	scanf("%[^\n]",s);
	__fpurge(stdin);
	for(i=0;s[i]== ' ' || s[i]== '\t' ;i++);
	for(j=0;s[i];i++)
	{
		s[++j] = s[i];
	}
	s[i]='\0';
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!= ' ' && s[i]!= '\t')
		j=i;
	}
	s[j+1]='\0';
	printf("After:%s\n",s);
}


