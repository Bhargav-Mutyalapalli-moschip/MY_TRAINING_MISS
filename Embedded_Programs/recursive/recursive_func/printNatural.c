#include<stdio.h>
int lim;
void main()
{
	int num;
	printf("enter number:");
	scanf("%d",&lim);


	Natural(1);

}
int Natural(int n)
{
	if(n == lim)
	{
		printf("%d",n);
		return n;
	}
	printf("%d ", n);
	n++;

	 n = Natural(n);
}

