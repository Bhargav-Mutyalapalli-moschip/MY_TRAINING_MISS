#include<stdio.h>
int main()
{
	long int x;
	scanf("%lx",&x);
	if((x>=0x0000)&&(x<0x4000))
	{
		if(x>=0x0000)
		{
			if(x<0x1000)
				printf("part 1 a sec");
			else if(x<0x2000)
				printf("part 1 b sec");
			else if(x<0x3000)
				printf("part 2 a sec");
			else
				printf("part 2 b sec");
		
		}
	}
		
	else
		printf("invalid address");
}
