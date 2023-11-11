 #include<stdio.h>
int main ()
{
	int num, reminder, Largest= 0,Sec_Largest=0;
	printf("Enter the Number :");
	scanf("%d",&num);
	while (num > 0)
	{
		reminder = num %-10;
		if (Largest < reminder)
		{
			Sec_Largest=Largest;
			Largest = reminder;
		}
		else if(reminder>=Sec_Largest)
			Sec_Largest=reminder;
		num = num / -10;
	}
	printf("The Second Largest Digit is %d", Sec_Largest);
	return 0;
}
