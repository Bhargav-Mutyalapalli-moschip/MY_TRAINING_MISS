#include<stdio.h>
void mul(int *num1,int*num2,int *res)
{
	*res=(*num1)*(*num2);
}
int main()
{
	int num1,num2,res;
	printf("enter the numbers for multiplication : ");
	scanf("%d%d",&num1,&num2);
	mul(&num1,&num2,&res);
	printf("output : %d \n",res);
}

