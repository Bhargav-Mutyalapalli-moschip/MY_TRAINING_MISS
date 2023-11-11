#include<stdio.h>
union num
{
	int i;
	long int l;
	float f;
	double d;
};
int main()
{
	union num var[10];

	var[0].i=10;
	var[1].l=11;
	var[2].f=10.3;
	var[3].d=25.654;
	printf("%d\t%d\t%f\t%lf\n",var[0].i,var[1].l,var[2].f,var[3].d);
}
