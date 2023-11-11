#include<stdio.h>
#define SET_BIT(value, pos) value |= (1U<< pos)
#define CLEAR_BIT(value, pos) value &= ~(1U<< pos)
#define TOGGLE_BIT(value, pos) value ^= (1U<< pos)
#define CHECK_BIT_IS_SET_OR_NOT(value, pos) value & (1U<< pos)
int main()
{
	int bits;
	unsigned int num;
	printf("enter the value:");
	scanf("%x",&num);
	printf("enter the position----(0 to 31):");
	scanf("%x",&bits);
	SET_BIT(num,bits);
	printf("The num:%x\n",num);
}




