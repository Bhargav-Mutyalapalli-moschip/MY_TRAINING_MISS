#include<stdio.h>
int main()
{
	unsigned int x;
	printf("enter the number");
	scanf("%d",&x);
	for(int i=0;i<=255;i++)
	{
		if(i==x)
		{
			switch(x)
			{
				case 0:
				printf("the bulbs are off position");
				case 1:
				printf("the bulb1 is on");
				case 2:
                                printf("the bulbs2 is on");
                                case 3:
                                printf("the bulb3 is on");
				case 4:
				printf("the bulb4 is on");
				default:
				printf("bulb is on");
			}
		}
		else{
			printf("it is not right");
		}
	}


}
