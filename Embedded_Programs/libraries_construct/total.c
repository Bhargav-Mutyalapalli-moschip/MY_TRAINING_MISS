#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include "pranav.h"
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
						//res=count_zero(num);
						printf("The zeros:%d\n",res);
						break;
					case 'b':
						printf("Enter the values to count the combinational bits:\n");
						scanf("%x",&num);
						//res=count_comb(num);
						printf("The 101 combinations is: %d\n",res);
						break;
					case 'c':
						printf("enter the value to set a bit:\n ");
						scanf("%x",&num);
						__fpurge(stdin);
						printf("enter the bit number to set:\n");
						scanf("%d",&bit);
						//res=set_operation(num,bit);
						printf("%x",res);
						break;
					case 'd':
						printf("Enter the value to clear the bit:\n");
						scanf("%x",&num);
						__fpurge(stdin);
						printf("enter the bit to clear:\n");
						scanf("%d",&bit);
						//res=clear_bit(num,bit);
						printf("%x",res);
						break;
					case 'e':
						printf("Enter the value for replacing:\n ");
						scanf("%x",&num);
						//res=replace_bits(num);
						printf("The output after replacing is:%x\n",res);
						break;
					case 'f':
						printf("Enter the value to convert into binary:\n");
						scanf("%x",&num);
						//bitwise_binary(num);
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
						//out=count_digits(num);
						printf("the count of digits is: %d\n",out);
						break;
					case 'd':
						printf("Enter the palindrome number\n");
						scanf("%d",&num);
						//out=palin_num(num);
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
						//out=decimal_binary(num);
						printf("The binary number is: %d\n",out);
						break;
					case'f':
						printf("Enter the Binary number\n");
						scanf("%d",&num);
						//out=binary_decimal(num);
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
						//swap_withthird(a,b);		
						break;
					case 'b':
						printf("enter the value to perform swapping without third variable\n");
						scanf("%d %d",&a,&b);
						//swap_withoutthird(a,b);
						break;
					case 'c':
						printf("enter the value to perform swapping with bitwise\n");
						scanf("%d %d",&a,&b);
						//swap_withbit(a,b);
						break;
					case 'd':
						printf("enter the byte or bits to be swapped: ");
						scanf("%d %d",&b1,&b2);
						__fpurge(stdin);
						printf("Enter the value to be swapped: ");
						scanf("%x",&num);
						//res=swap_bits(num,b1,b2);
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
						//check=ascii_char(up);
						if(check==-1)
							printf("invalid character\n");
						else
							printf("The letter is:%c\n",check);

						break;
					case 'b':
						printf("enter the value:\n");
						scanf("%c",&x1);
						//check=ascii_conver(x1);
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
				//gotostat_prog(a,b);
				break;
			default:
				printf("invalid option");



		



		}
	}
}
