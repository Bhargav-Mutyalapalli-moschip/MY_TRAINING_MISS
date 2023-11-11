#include<stdio.h>
static int x=10;
extern void (*fptr)();
int *ptr=&x;
int main()
{
        int h,l=22,k=30;
        scanf("%d",&h);
        printf("%d-----%d-------%d\n",h,++l,k);
        fptr();

}

