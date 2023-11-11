#include<stdio.h>
#include<string.h>
int main()
{
	char str[50];
	printf("enter a string:");
	scanf("%s",str);
	int i,j,count=0;
	for(i=0;str[i]!='\0';i++)
	{
		count=1;
		if(str[i]=='-')
		continue;
		for(j=i+1;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
			{
				count++;
				str[j]='-';
			}

		}
		printf("The char:%c||||------The count:%d\n",str[i],count);
	}
}
	
		


