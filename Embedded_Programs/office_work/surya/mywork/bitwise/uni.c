#include<stdio.h>
struct node1
{
	char a[20];
	int b;
	union node2
	{
		double c;
		struct node3
		{
			char d[15];
			float e;

		}x;
	}y;
};
int main()
{
	struct node1 z.y.c=11.223;
	
	printf("%d------%d-----%d\n",sizeof(z.y.x),sizeof(z.y),sizeof(z));
	printf("%lf",z.y.c);

}
