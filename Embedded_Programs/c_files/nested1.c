#include<stdio.h>
int main()
{
	int a,b,sum=0,temp,rem,i=1;
	scanf("%d %d",&a,&b);
	if(a>b)
	temp=a,a=b,b=temp;
	
	do{

		sum=0;
		temp=a;
		i=1;
		do{
			rem=temp%2;
			/*if(rem>1)
			{
				break;
			}*/

			sum=sum+(rem*i);
			temp=temp/2;
			i=i*10;

		}while(temp!=0);
		
		/*if(rem>1)
		{
			a++;
			continue;
		}*/

		printf("%d-----%d\n",a,sum);
		a++;


	

	}while(b>=a);


}



