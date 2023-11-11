#include<stdio.h>
int main()
{
int *p, *c, i;
i = 5;
p = (int*)
(malloc(sizeof(i)));
printf("\n%d",*p);
*p = 10;
printf("\n%d %d",i,*p);
c = (int*) malloc(2);
printf("\n%d\n",*c);
}
