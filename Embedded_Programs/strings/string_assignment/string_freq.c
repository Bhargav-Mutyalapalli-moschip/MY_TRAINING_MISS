#include<stdio.h>
int main()
{
	char str[200];
	printf("enter the string\n");
	scanf("%s",str);
	int i,j,count=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
			continue;
		count=1;
		for(j=i+1;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
			{
				count++;
				str[j]=' ';
			}
		}
		printf("The characater is %c-------The count is:%d\n",str[i],count);
	}
}


