#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[100],n=0;
    printf("enter the number to be converted :");
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        a[i]=n%2;
        n=n/2;
    }
    for(int i=i-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
}
