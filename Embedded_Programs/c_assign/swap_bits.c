int swap_bits(unsigned int num,int b1,int b2)
{
	int temp;
	unsigned int v;
	(b1>b2)?(temp=b1,b1=b2,b2=temp) : 0;
	v=(num & ~((0x1<<b1)|(0x1<<b2)))|((num&(0x1<<b1))<<(b2-b1))|((num&(0x1<<b2))>>(b2-b1));
	return v;
	
}
