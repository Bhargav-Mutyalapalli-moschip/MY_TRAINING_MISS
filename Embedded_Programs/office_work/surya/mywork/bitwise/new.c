#include<stdio.h>
int main()
{
	int arr[10]={108,12,40,50,40,60,9,120,120};
	int big,s_big,i,j;
	big=arr[0];
	s_big=0;
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(arr[i]>arr[j])
			{
				if(arr[i]>big)
					big=arr[i];
			}

			else
				i++;
		}
	}
	printf("%d\n",big);
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(arr[i]>arr[j])
			{
				if(arr[i]==big || arr[j]==big)
				{
					i++;
					j++;
				}
				if(arr[i]>s_big)
					s_big=arr[i];
			}
			else
				i++;

		}
	}
	printf("%d\n",s_big);


}

