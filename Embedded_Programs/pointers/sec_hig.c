#include<stdio.h>
int main()
{
	int temp,rem,larg=0,sec_high=0,third_high=0;
	scanf("%d",&temp);
	while(temp>0)
	{
		rem=temp%10;
		temp=temp/10;
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





