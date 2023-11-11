#include<stdio.h>
void main()
{
	struct 
	{
		char a[20];
		int b;
		union
		{
			double c;
			struct
			{
				char d[15];
				float g;
			}x;
		}y;
	}z;
	printf("%d---------%d---------%d\n",sizeof(z.y.x),sizeof(z.y),sizeof(z));
}

