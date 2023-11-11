int binary_decimal(int num)
{
	int bin=0,rem,i=1,temp;
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		if(rem>1)
		return -1;
		bin=bin+(rem*i);
		temp=temp/10;
		i=i*2;
	}
	return bin;
}
