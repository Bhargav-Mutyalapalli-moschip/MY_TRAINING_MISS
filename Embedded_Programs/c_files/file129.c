#include<stdio.h>
int main()
{
	unsigned int x;
	scanf("%x",&x);
	x=(x& ~((0xff<<24)|(0xff<<0)))|((x &(0xff<<0))<<(24-0))|((x & (0xff<<24))>>(24-0));
	 printf("%x",x);
}
