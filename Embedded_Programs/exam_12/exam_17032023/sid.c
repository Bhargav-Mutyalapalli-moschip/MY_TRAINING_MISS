#include<stdio.h>
int main()
{
	char arr[100],temp;
	int i,j;
	printf("\nentr the string : ");
	scanf("%s",arr);
	printf("original string : %s \n",arr);
	for(i=0;arr[i]!='\0';i++)
	{
		for(j=i+1;arr[j]!='\0';j++)
		{
			if((arr[i]>='A')&&(arr[i]<='Z'))
			{

				if((arr[j]>='A')&&(arr[j]<='Z'))
				{
					if(arr[i]>arr[j])
					{
						temp=arr[i];
						arr[i]=arr[j];
						arr[j]=temp;
					}
				}

			}
			if((arr[i]>='a')&&(arr[i]<='z'))
			{
				if((arr[j]>='a')&&(arr[j]<='z'))
				{
					if(arr[i]>arr[j])
					{
						temp=arr[i];
						arr[i]=arr[j];
						arr[j]=temp;
					}
				}
			}
		}
	}
	printf("sorted string : %s \n",arr);
}
