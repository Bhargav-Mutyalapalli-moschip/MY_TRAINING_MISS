#include<stdio.h>
#include<string.h>
int main()
{
	char str[50];
	scanf("%s",str);
	int i,j,count1=0,count2=0,len;
	for(i=0;str[i]!='\0';i++)
	{
		for(j=i+1;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
			{



