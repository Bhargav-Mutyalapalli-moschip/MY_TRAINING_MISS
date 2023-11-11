#include<stdio.h>
int main()
{
	char arr[100];
	printf("Enter the string to remove spaces\n");
	scanf("%[^\n]",arr);
	int i,j,count=0,h;
	for(i=0;arr[i]!='\0';i++)
	{
		if(arr[i]==' ')
		{
			count++;
		}
		if(count>1)
		{
			for(j=0;arr[j]!='\0';j++)
			if(arr[j]==' ')
				h++;
			else
				arr[j]=arr[j+1];

		}
	}
	arr[i]='\0';
	printf("%s\n",arr);
}
