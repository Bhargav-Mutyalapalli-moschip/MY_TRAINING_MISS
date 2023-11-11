main()
{
	signed int bit=512,mbit;
	{
		mbit=~bit;
		bit=bit&~bit;
		printf("%d\n %d\n",bit,mbit);
	}
}
