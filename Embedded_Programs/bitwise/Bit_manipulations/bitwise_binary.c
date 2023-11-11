void bitwise_binary(unsigned int num)
{
	int i;
	for(i=31;i>=0;i--)
	{
		if(((num&(0x1)<<i)>>i)==0)
		{
			printf("0");

		}
		else
			printf("1");
         }
}
