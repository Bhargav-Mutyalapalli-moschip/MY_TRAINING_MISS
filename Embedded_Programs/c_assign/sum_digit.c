int sum_digit(int num)
{
	int i,rem,sum=0,temp;
	temp=num;
	while(temp > 0){
		rem = temp % 10;
		temp = temp / 10;
		sum = sum + rem;
	}
	return sum;
}
