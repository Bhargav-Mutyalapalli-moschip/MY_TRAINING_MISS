#include<stdio.h>
void func(int n);
int main()
{
        int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<10;i++)
	{
		func(n);
	}

}
void func(int n)
{
	static int step;
	step=step+n+1;
	printf("%d",step);
}
	
