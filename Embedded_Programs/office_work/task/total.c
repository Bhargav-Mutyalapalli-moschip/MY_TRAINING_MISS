#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include "ram.h"

void main()
{
	while(1)
	{
		
		char sub_prog,check,up,x1;
		int prog,res,bit,out,a,b,b1,b2,n;
		unsigned int num,v,x;
		unsigned int mask=0x1;
		int bit1=6;

		printf("SELECT THE OPTION\n 2.Bitwise operator\n 1.Arthimetic operator\n 3.Swapping technique\n 4.Ascii conversions\n 5.Fabnoc series\n 6.Goto program\n 7.Macros\n");
		scanf("%d",&prog);
		__fpurge(stdin);
		switch(prog)
		{
			case 0:exit(0);

			case 1:
				printf("Select the option:\n a.Reverse a number\n b.Sum of digits\n e.Count the digits\n d.Palindrome number\n c.Decimal to binary\n f.Binary to decimal\n g.Even or odd\n");
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
					case 'e':
						printf("Enter the decimal value: ");
						scanf("%d",&num);
						out=decimal_binary(num);
						printf("The binary number is: %d\n",out);
						break;
					case'c':
					default:
						printf("invalid option");







				}
				break;
		}
	}
}
