int replace_bits(unsigned int num)
{
	int i;
	for(i=0;i<32-3;i++)
	{
		if(((num&(0x7)<<i)>>i)==(0x5))
		{
			num=num|(0x7)<<i;
		}
	}
	return num;
}
