#include<stdio.h>
#include<string.h>
int main()
{
	int i,k,count=0;
	char str[30];
	char str1[5]={'a','e','i','o','u'};
	printf("Enter the string to check vowels\n");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
		for(k=0;k<5;k++)
		{
			if(str[i]==str1[k])
			count++;
		}
	}
	printf("The vowels are:%d\n",count);
}



