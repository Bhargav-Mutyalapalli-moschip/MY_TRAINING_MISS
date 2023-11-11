int count_zero(unsigned int num)
{
         num;
	int i,count=0,count1=0;
	for(i=0;i<=31;i++)
	{
		if((num&(0x1))==0)
			count++;
		else
			count1++;
		num=num>>1;
	}
	return count;
}
