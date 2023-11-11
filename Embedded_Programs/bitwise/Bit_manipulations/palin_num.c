int palin_num(int num)
{
	int i,sum=0,rem,temp;
	temp=num;
	while(temp > 0){
		rem = temp % 10;

		temp = temp / 10;

		sum = (sum*10)+rem;
	}
	if(sum==num)
		return 0;
	else
		return -1;
}
