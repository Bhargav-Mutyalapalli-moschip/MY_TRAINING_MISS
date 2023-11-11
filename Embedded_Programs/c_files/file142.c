#include<stdio.h>
int main()
{
	char d,f;
	scanf("%c",&d);
	if((d>=0)&&(d<=127))
	{
		if((d>=65)&&(d<=90))
		{
			f=f+32;

			d=d+32;
			printf("%c",d);
		}
		else
		{
			if((d>=97)&&(d<=120))
			{
				
				d=d-32;
				printf("%c",d);
			}
			else
				printf("it is a special");
		}
	}
}
