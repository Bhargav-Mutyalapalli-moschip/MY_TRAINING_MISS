#include<stdio.h>
#include "ram.h"
void main()
{
	unsigned int res,num;
	scanf("%x",&num);
	printf("Main -%p num->%p--0x%x\n",main,&num,num);
	res=replace_bitwise(num);
	printf("Main -%p res->%p--0x%x\n",main,&res,res);
}
