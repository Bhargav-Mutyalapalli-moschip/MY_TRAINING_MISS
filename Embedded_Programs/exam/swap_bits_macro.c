#include<stdio.h>
#include<stdlib.h>
#define SWAP_BYTES(u32Value) ((u32Value & 0x000000FF) << 24)|((u32Value & 0x0000FF00) << 8) |((u32Value & 0x00FF0000) >> 8) |((u32Value & 0xFF000000) >> 24)
int main()
{
	unsigned int x=0x11223344,h;
	h=SWAP_BYTES(x);
	printf("The:%x\n",x);
	printf("The:%x\n",h);
}


