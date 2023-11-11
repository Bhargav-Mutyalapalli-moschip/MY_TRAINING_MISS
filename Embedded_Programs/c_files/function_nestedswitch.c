#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
int count_zero(unsigned int num)
{
         num;
	int i,count=0,count1=0;
	for(i=0;i<=31;i++)
	{
		if((num&(0x1))==0)
			count++;
		else
			count1++;
		num=num>>1;
	}
	return count;
}
int count_comb(unsigned int num)
{
	num;
	int i,count=0;
	for(i=0;i<32-3;i++)
	{
		if((num&(0x7))==(0x5))
			count++;
		num=num>>1;
	}
	return count;
}
int set_operation(unsigned int num,int bit)
{
	//int bit;
	unsigned int out,mask=0x1;
        out=num|(mask<<bit);
	return out;
	
	
}
int clear_bit(unsigned int num,int bit)
{
	unsigned int out,mask=0x1;
	out=num&(~(mask<<bit));
	return out;
}
int replace_bits(unsigned int num)
{
	int i;
	for(i=0;i<32-3;i++)
	{
		if(((num&(0x7)<<i)>>i)==(0x5))
		{
			num=num|(0x7)<<i;
		}
	}
	return num;
}
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
int binary_decimal(int num)
{
	int bin=0,rem,i=1,temp;
	temp=num;
	while(temp!=0)
	{
		rem=temp%10;
		if(rem>1)
		return -1;
		bin=bin+(rem*i);
		temp=temp/10;
		i=i*2;
	}
	return bin;
}
int even_odd(int num)
{
	int temp= num;
	if(temp % 2 == 0)
		return 0;
	else
		return 1;
}
void swap_withthird(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	printf("A after swapping:%d\n B after swapping:%d\n",a,b);
}
void swap_withoutthird(int a,int b)
{
	a=a+b;b=a-b;a=a-b;
	printf("A after Swapping:%d\n B after swapping:%d\n",a,b);

}
void swap_withbit(int a,int b)
{
	a=a^b;
	b=a^b;
	a=a^b;
	printf("A after swapping:%d\n B after swapping:%d\n",a,b);
}
int swap_bits(unsigned int num,int b1,int b2)
{
	int temp;
	unsigned int v;
	(b1>b2)?(temp=b1,b1=b2,b2=temp) : 0;
	v=(num & ~((0x1<<b1)|(0x1<<b2)))|((num&(0x1<<b1))<<(b2-b1))|((num&(0x1<<b2))>>(b2-b1));
	return v;
	
}
char ascii_char(char up)
{
	if((up>=65)&&(up<=90))
	{
		up=up+32;
		return up;
	}
	else if((up>=97)&&(up<=120))
	{
		up=up-32;
		return up;
	}
	else
		return -1;
}	
int ascii_conver(char x1)
{
	if((x1>=47)&&(x1<=55))
	{
		x1=x1-48;
		return x1;
	}
	else
		return -1;
}
void fab_series(int a,int b,int n)
{
	int c;
	while(n>0)
	{
		c=a+b;
		a=b;
		b=c;
		printf("%d ",b);
		n--;
		
	}
	
	
}
void gotostat_prog(int a,int b)
{
	int sum=0,temp=0,rem,i=1,temp1=0;
        if(a>b)
        temp=a,a=b,b=temp;
        

binary:
       temp=a;


       if(b>=a)
       {


               sum=0;
               i=1;


binary1:

	       rem=temp%10;
	       if(rem>1)
	       {
		       a++;
		       goto binary;
	       }
	       sum=sum+(rem*i);
	       temp=temp/10;
	       i=i*2;
	       if(temp!=0)
		       goto binary1;
	       printf("%d %d\n",a,sum);
	       a++;
	       if(rem<=1)
		       goto binary;

       }
}







void main()
{
	while(1)
	{
		
		char sub_prog,check,up,x1;
		int prog,res,bit,out,a,b,b1,b2,n;
		unsigned int num,v;

		printf("SELECT THE OPTION\n 1.Bitwise operator\n 2.Arthimetic operator\n 3.Swapping technique\n 4.Ascii conversions\n 5.Fabnoc series\n 6.Goto program\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 0:exit(0);

			case 1:
				printf("SELECT THE OPTION TO PERFORM THE BITWISE OPERATIONS\n a.Count no of Zeros\n b.Count the combinational bits\n c.Set the bits\n d.Clear the bits\n e.Replacing 101 with 111\n f.Binary conversion\n");
				scanf("%c",&sub_prog);
				switch(sub_prog)
				{
					case 0:exit(0);

					case 'a':
						printf("Enter the value to count number of zeros\n");
						scanf("%x",&num);
						res=count_zero(num);
						printf("The zeros:%d\n",res);
						break;
					case 'b':
						printf("Enter the values to count the combinational bits:\n");
						scanf("%x",&num);
						res=count_comb(num);
						printf("The 101 combinations is: %d\n",res);
						break;
					case 'c':
						printf("enter the value to set a bit:\n ");
						scanf("%x",&num);
						__fpurge(stdin);
						printf("enter the bit number to set:\n");
						scanf("%d",&bit);
						res=set_operation(num,bit);
						printf("%x",res);
						break;
					case 'd':
						printf("Enter the value to clear the bit:\n");
						scanf("%x",&num);
						__fpurge(stdin);
						printf("enter the bit to clear:\n");
						scanf("%d",&bit);
						res=clear_bit(num,bit);
						printf("%x",res);
						break;
					case 'e':
						printf("Enter the value for replacing:\n ");
						scanf("%x",&num);
						res=replace_bits(num);
						printf("The output after replacing is:%x\n",res);
						break;
					case 'f':
						printf("Enter the value to convert into binary:\n");
						scanf("%x",&num);
						bitwise_binary(num);
						//printf("%x",res);
						break;
					default:
						printf("invalid option");



				}
				break;
			case 2:
				printf("Select the option:\n a.Reverse a number\n b.Sum of digits\n c.Count the digits\n d.Palindrome number\n e.Decimal to binary\n f.Binary to decimal\n g.Even or odd\n");
				scanf("%c",&sub_prog);
				__fpurge(stdin);
				switch(sub_prog)

				{
					case 0:exit(0);

					case 'a':
						printf("Enter the value to be reversed:\n ");
						scanf("%d",&num);
						out=reverse_num(num);
						printf("The Reversed number:%d\n",out);
						break;
					case 'b':
						printf("Enter the number for sum of digits: ");
						scanf("%d",&num);
						out=sum_digit(num);
						printf("The output is: %d\n",out);
						break;
					case 'c':
						printf("Enter the number: ");
						scanf("%d",&num);
						out=count_digits(num);
						printf("the count of digits is: %d\n",out);
						break;
					case 'd':
						printf("Enter the palindrome number\n");
						scanf("%d",&num);
						out=palin_num(num);
						if(out==0)
						{
							printf("palindrome");
							break;
						}
						else
							printf("not a palindrome");
						break;
					case 'e':
						printf("Enter the decimal value: ");
						scanf("%d",&num);
						out=decimal_binary(num);
						printf("The binary number is: %d\n",out);
						break;
					case'f':
						printf("Enter the Binary number\n");
						scanf("%d",&num);
						out=binary_decimal(num);
						if(out<=0)
							printf("Invalid input\n");
						else
							printf("The decimal value is:%d\n",out);
						break;
					case 'g':
						printf("Enter the number to check even or odd\n");

						scanf("%d",&num);
						out=even_odd(num);
						if(out==0)
							printf("EVEN\n");
						else
							printf("ODD\n");

						break;
					default:
						printf("invalid option");







				}
				break;
			case 3:
				printf("Selected the option to perform the swapping techniques:\n a.with third variable\n b.without third variable\n c.without third variable(Bitwise operator)\n d.Within bytes swapping\n ");
				scanf("%c",&sub_prog);
				__fpurge(stdin);
				switch(sub_prog)
				{
					case 0:exit(0);
					case 'a':
						printf("enter the value to perform swapping by using of third variable:\n");
						scanf("%d %d",&a,&b);
						printf("A before swapping:%d\n B before swapping:%d\n",a,b);
						swap_withthird(a,b);		
						break;
					case 'b':
						printf("enter the value to perform swapping without third variable\n");
						scanf("%d %d",&a,&b);
						swap_withoutthird(a,b);
						break;
					case 'c':
						printf("enter the value to perform swapping with bitwise\n");
						scanf("%d %d",&a,&b);
						swap_withbit(a,b);
						break;
					case 'd':
						printf("enter the byte or bits to be swapped: ");
						scanf("%d %d",&b1,&b2);
						__fpurge(stdin);
						printf("Enter the value to be swapped: ");
						scanf("%x",&num);
						res=swap_bits(num,b1,b2);
						printf("%x",res);
						break;
					default:
						printf("invalid option");




				}
				break;
			case 4:
				printf("select the option to perform ASCII conversions\n a.capital to small and viceverse\n b.character constant to integer constant\n");
				scanf("%c",&sub_prog);
				__fpurge(stdin);
				switch(sub_prog)
				{
					case 'a':
						printf("Enter the character to convert:\n");
						scanf("%c",&up);
						check=ascii_char(up);
						if(check==-1)
							printf("invalid character\n");
						else
							printf("The letter is:%c\n",check);

						break;
					case 'b':
						printf("enter the value:\n");
						scanf("%c",&x1);
						check=ascii_conver(x1);
						if(check==-1)
							printf("invalid constant");
						else
							printf("the value is:%d\n",check);

						break;

				}
				break;
			case 5:
				printf("enter the values:\n");
				scanf("%d %d",&a,&b);
				printf("range");
				scanf("%d",&n);
				fab_series(a,b,n);
				break;
			case 6:
				printf("enter the number:\n");
				scanf("%d %d",&a,&b);
				gotostat_prog(a,b);
				break;
			default:
				printf("invalid option");







		}
	}
}
