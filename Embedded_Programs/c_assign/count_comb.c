int count_comb(unsigned int num)
{
	num;
	int i,count=0;
	for(i=0;i<32-3;i++)
	{
		if((num&(0x7))==(0x5))
			count++;
		num=num>>1;
	}
	return count;
}
