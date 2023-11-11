#include<stdio.h>
int main()
{
	int seconds,sec;
	double hours,minutes;
	scanf("%d",&seconds);
	hours=(double)seconds/3600;
	minutes=(double)seconds/60;
	sec=(int)hours*60*(int)minutes;
	printf("%d\n hours is %lf\n minutes is %lf\n %d",seconds,hours,minutes,sec);
}
