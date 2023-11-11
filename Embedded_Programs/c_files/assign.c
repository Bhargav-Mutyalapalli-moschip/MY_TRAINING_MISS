#include<stdio.h>
int main()
{
	int sum=0,rem,temp,x,prog,num,count,i=1;
	printf("Enter the program number\n 1-Reverse\n 2-Sum of digits\n 3-Count\n 4-Palindrome\n 5-Binary\n 6-Even or Odd\n   ");
	scanf("%d",&prog);
	switch(prog)
	{
		case 1:
			printf("Enter the value to be reversed:\n ");
			scanf("%d",&num);
			sum=0;
			temp=num;
			while(temp!=0)
			{
				rem=temp%10;
				sum=(sum*10)+rem;
				temp=temp/10;
			}
			printf("The Reversed number:%d\n",sum);
			break;


		case 2:
			printf("Enter the number for sum of digits: ");
			scanf("%d",&num);
			temp = num;
			sum=0;
			while(temp > 0){
				rem = temp % 10;

				temp = temp / 10;

				sum = sum + rem;
			}
			printf("The sum of digits is: %d\n",sum);
			break;

		case 3:
			printf("Enter the number: ");
			scanf("%d",&num);
			count=0;
			temp=num;
			if(temp!=0)
			{
				while(temp!=0)
				{
					temp=temp/10;
					count++;
				}
				printf("The Count of digits is: %d\n",count);
			}
			else{
				count++;
			        printf("The Count of digits is: %d\n",count);
			}

			break;
		case 4:
			printf("Enter the palindrome number\n");
			scanf("%d",&num);
			temp = num;
			sum=0;
			while(temp > 0){
				rem = temp % 10;

				temp = temp / 10;

				sum = (sum*10)+rem;
			}
			if(sum == num) printf("The number is a palindrome\n");
			else printf("Number is not a palindrome\n");
			break;


		case 5:
			printf("Enter the decimal value: ");
			scanf("%d",&num);
			sum=0;
			i=1;
			temp=num;
			while(temp!=0)
			{
				rem=temp%2;
				sum=sum+(rem*i);
				temp=temp/2;
				i=i*10;
			}
			printf("The binary number is: %d\n",sum);
			break;
		case 6:
			printf("Enter the number to check even or odd\n");
			scanf("%d",&num);
			temp = num;
			if(temp % 2 == 0)
				printf("Even Number\n");
			else
				printf("Odd Number\n");

			break;


		default:
			printf("nothing");
	}
}


