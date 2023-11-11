#include<stdio.h>
int main()
{
	char arr[100];
	scanf("%[^\n]",arr);
	int i,j;
	arr[0]=arr[0]-32;
	for(i=0;arr[i]!='\0';i++)
	{
			if(arr[i]==' ')
			{
				arr[i-1]=arr[i-1]-32;
				arr[i+1]=arr[i+1]-32;
			}
	}
	arr[i-1]=arr[i-1]-32;
	printf("%s",arr);
}
