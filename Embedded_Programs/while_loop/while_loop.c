#include<stdio.h>
int main()
{
	int i;
	for(i=0;i<5;i++);
		printf("%d\n",i);
	i=10;
	while(i<5);
	printf("%d\n",i++);
	i=0;
	while(i<5);
	printf("%d\n",i++);
}

