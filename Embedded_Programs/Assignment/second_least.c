#include<stdio.h>
#include<stdio_ext.h>
#include<limits.h>
int main()
{
	int arr[10]={0,2,3,1,6,5,4,9,8,7};
	int i,low=INT_MAX,sec_low=INT_MAX;
	//int i,low,sec_low;
	printf("LOw:%d------Sec_low:%d\n",low,sec_low);
/*	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
		__fpurge(stdin);
	}*/
        low=arr[0];
	for(i=0;i<10;i++)
	{
		if(arr[i]<low)
		{
			sec_low=low;
			low=arr[i];
		}
		else if(sec_low > low && arr[i] < sec_low)
		sec_low=arr[i];
	}
	printf("LOw:%d------Sec_low:%d\n",low,sec_low);
}


	
