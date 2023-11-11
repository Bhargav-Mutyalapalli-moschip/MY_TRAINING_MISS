#include<stdio.h>
int main()
{
    int arr[5],sum=0,i;
    printf("enter the elements: ");
    for(int i=0;i<=5;i++)
    {
        scanf("%d",&arr[i]);
        
    }
    for(i=0;i<=5;i++)
    {
        sum =sum+arr[i];
        printf("%d",sum);
        
    }
    
}
