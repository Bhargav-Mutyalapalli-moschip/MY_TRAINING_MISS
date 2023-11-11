int reverse_num(int num)
{
	int i,rem,sum=0,temp;
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		sum=(sum*10)+rem;
		temp=temp/10;
	}
	return sum;
}
