#include<stdio.h>
int main()
{
	int temp,rem,larg=0,sec_high=0,third_high=0,i;
	int arr[10]={1,44,55,2,3,88,99,99,22,33};
	i=0;
	for(i=0;i<10;i++)
	{
		rem=arr[i];
		if(rem>=larg){
			if(rem==larg)
			{
				continue;
			}
			third_high=sec_high;
			sec_high=larg;
		        larg=rem;

		}
		else if(rem>=sec_high)
			sec_high=rem;
		else if(rem>=third_high)
			third_high=rem;
		
	}
	printf("%d-------------%d-----------%d\n",larg,sec_high,third_high);
}





