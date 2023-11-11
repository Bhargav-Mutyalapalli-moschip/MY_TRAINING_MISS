int decimal_binary(int num)
{
	int dec=0,rem,i=1,temp;
	temp=num;
	while(temp!=0)
	{
		rem=temp%2;
		dec=dec+(rem*i);
		temp=temp/2;
		i=i*10;
	}
	return dec;
}
