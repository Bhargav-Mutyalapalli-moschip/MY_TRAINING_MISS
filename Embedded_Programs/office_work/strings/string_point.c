#include<stdio.h>
int main()
{
	char arr[100];
	char str1[100];
	scanf("%[^\n]",arr);
	int i,j,count=0,k,temp;
	for(i=0;arr[i]!='\0';i++)
	{
		
		if(arr[i]==' '){
			count++;
		}
		if(count>1) 
		{
			for(j=i;j>=i;j++)
			{
				arr[j]=arr[j+1];
			}
			i--;
			count=0;


		}
		arr[i]='\0';
		printf("%s\n",arr);
	}
}
