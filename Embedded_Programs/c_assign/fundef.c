int replace_bitwise(unsigned int num)
{
	//printf("Main -%p num->%p--0x%u\n",main,&num,num);
	int i;
	for(i=0;i<32;i++)
	{

		if(((num&(0x7)<<i)>>i)==(0x5))
		num=num|((0x7)<<i);
	}
	return num;
}

