int count_digits(int num)
{
	int i,sum=0,rem,temp,count=0;
	temp=num;
	if(temp!=0)
	{
		while(temp!=0)
		{
			temp=temp/10;
			count++;
		}
		return count;
	}
	else{
		count++;
		return count;
	}
}
