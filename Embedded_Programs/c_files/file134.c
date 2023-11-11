#include<stdio.h>
int main()
{
	int v;
	scanf("%x",v);
	v=((v&(0xff<<0))%2==0) ? printf("even"):printf("odd");
}

