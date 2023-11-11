#include<stdio.h>
int main()
{
	char *str="hello";
	int i,j;
	printf("%d",strlen(str));
	j=strlen(str);

	for(i=0;i<j;i++)
	{
		printf("%s\n",str++);
		printf("the length:%d\n",strlen(str));
	}
		
}
