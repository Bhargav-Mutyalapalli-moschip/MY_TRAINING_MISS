#include<stdio.h>
int main()
{
	unsigned int a;
	unsigned int temp,byte1,byte2;
	printf("enter the number\n");
	scanf("%x",&a);
	printf("%x\n",a);
	printf("enter the bytes ");
	scanf("%d:%d",&byte1,&byte2);
	byte1>byte2?(temp=byte2,byte2=byte1,byte1=temp,printf("%d%d\n",byte1,byte2)):printf("false");
	a=(a&(~((0xff<<byte2)|(0xff<<byte1))))|((a&(0xff<<byte1))<<(byte2-byte1))|((a&(0xff<<byte2))>>(byte2-byte1));
	printf("%x\n",a);
}
