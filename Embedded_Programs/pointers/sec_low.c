
#include<stdio.h>
int main()
{
	int temp,rem,larg=0,sec_high=0,third_high=0,small=0,a=0,i;
	scanf("%d",&temp);
	a=temp%10;
	while(temp>0)
	{
		rem=temp%10;
		temp=temp/10;
		/*for(i=0;i<1;i++)
			a=rem;*/
		if(a>=rem)
		{
			small=a;
			

			a=rem;
		}
		else if(rem<=small)
			small=rem;
	}
	printf("%d-------------%d-----------%d\n",small,sec_high,a);
}





