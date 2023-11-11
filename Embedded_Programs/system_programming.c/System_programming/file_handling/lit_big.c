#include<stdio.h>
int main()
{
	int i,j;
	unsigned int num=0x11223341;
	unsigned int var=0,val=num;;
	for(i=0,j=31;i<32;i++,j--)
	{
	/*	var=((val&(0x1<<i))<<j);
		printf("The hexa check:%x\n",var);*/
		//var=var|((val&(0x1))<<j);



	}
	printf("The out:0x%x\n",var);
}

