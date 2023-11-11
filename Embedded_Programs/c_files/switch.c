#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int num,out,v;
	int count1=0,bit,a,b,b1,b2,j,n,c;
	int sum=0,rem,temp,x,prog,count,i=1;
	char sub_prog,up,x1;
	unsigned int mask=0x1;
	printf("SELECT THE OPTION\n 1.Bitwise operator\n 2.Arthimetic operator\n 3.Swapping technique\n 4.Ascii conversions\n 5.Fabnoc series\n");
	scanf("%d",&prog);
	__fpurge(stdin);
	switch(prog)
	{
		
		case 1:
			printf("SELECT THE OPTION TO PERFORM THE BITWISE OPERATIONS\n a.Count no of Zeros\n b.Count the combinational bits\n c.Set the bits\n d.Clear the bits\n e.Replacing 101 with 111\n f.Binary conversion\n");
			scanf("%c",&sub_prog);
			switch(sub_prog)
			{
				
				case 'a':
					printf("Enter the value to count number of zeros and ones\n");
					scanf("%x",&num);
					for(i=0;i<=31;i++)
					{
						if((num&(0x1))==0)
					        count++;
						else
							count1++;
						num=num>>1;
					}
					printf("The zeros:%d\n The ones:%d\n",count,count1);
					break;


				case 'b':
					printf("Enter the values to count the combinational bits:\n");
					scanf("%x",&num);
					for(i=0;i<32-3;i++)
					{
						if((num&(0x7))==(0x5))
						count++;
						num=num>>1;
					}
					printf("The 101 combinations is: %d\n",count++);
					break;


				case 'c':
					printf("enter the value to set a bit:\n ");
					scanf("%x",&num);
					__fpurge(stdin);
					printf("enter the bit number to set:\n");
					scanf("%d",&bit);
					out=num|(mask<<bit);
					printf("%x",out);
					break;


				case 'd':
					printf("Enter the value to clear the bit:\n");
					scanf("%x",&num);
					__fpurge(stdin);
					printf("enter the bit to clear:\n");
					scanf("%d",&bit);
					out=num&(~(mask<<bit));
					printf("%x",out);
					break;


				case 'e':
					printf("Enter the value for replacing:\n ");
					scanf("%x",&num);
					for(i=0;i<32-3;i++)
					{
						if(((num&(0x7)<<i)>>i)==(0x5))
						{
							num=num|(0x7)<<i;
						}
					}
					printf("The output after replacing is:%x\n",num);
					break;


				case 'f':
					printf("Enter the value to convert into binary:\n");
					scanf("%x",&num);
					for(i=31;i>=0;i--)
                                        {
                                                if(((num&(0x7)<<i)>>i)==0)
                                                {
							printf("0");
                                                  
                                                }
						else
							printf("1");
                                        }
					break;







			}
			break;
		case 2:
			printf("Select the option:\n a.Reverse a number\n b.Sum of digits\n c.Count the digits\n d.Palindrome number\n e.Decimal to binary\n f.Binary to decimal\n g.Even or odd\n");
			scanf("%c",&sub_prog);
			__fpurge(stdin);
			switch(sub_prog)
			{
				case 'a':
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


				case 'b':
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

				case 'c':
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
				case 'd':
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


				case 'e':
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

				case'f':
					printf("Enter the Binary number\n");
                                        scanf("%d",&num);
                                        sum=0;
                                        i=1;
                                        temp=num;
                                        while(temp!=0)
                                        {
                                                rem=temp%10;
						if(rem>1)
						{
							num++;
							break;
						}
                                                sum=sum+(rem*i);
                                                temp=temp/10;
                                                i=i*2;
                                        }
                                        printf("The decimal number is: %d\n",sum);
					num++;
                                        break;

				case 'g':
					printf("Enter the number to check even or odd\n");
					scanf("%d",&num);
					temp = num;
					if(temp % 2 == 0)
						printf("Even Number\n");
					else
						printf("Odd Number\n");

					break;







			}
			break;
		case 3:
			printf("Selected the option to perform the swapping techniques:\n a.with third variable\n b.without third variable\n c.without third variable(Bitwise operator)\n d.Within bytes swapping\n e.Total byte swapping\n");
			scanf("%d",&sub_prog);
			__fpurge(stdin);
			switch(sub_prog)
			{
				case 'a':
					printf("enter the value to perform swapping by using of third variable:\n");
					scanf("%d %d",&a,&b);
					printf("A before swapping:%d\n B before swapping:%d\n",a,b);
					temp=a;
					a=b;
					b=temp;
					printf("A after swapping:%d\n B after swapping:%d\n",a,b);
					break;


				case 'b':
					printf("enter the value to perform swapping without third variable\n");
					scanf("%d %d",&a,&b);
					printf("A after swapping:%d\n B after swapping:%d\n",a,b);
					a=a+b;b=a-b;a=a-b;
					printf("A after swapping:%d\n B after swapping:%d\n",a,b);
					break;

				case 'c':
					printf("enter the value to perform swapping with bitwise\n");
					scanf("%d %d",&a,&b);
					printf("A after swapping:%d\n B after swapping:%d\n",a,b);
					a=a^b;
					b=a^b;
					a=a^b;
					printf("A after swapping:%d\n B after swapping:%d\n",a,b);
					break;


				case 'd':
					printf("enter the byte or bits to be swapped: ");
					scanf("%d %d",&b1,&b2);
					__fpurge(stdin);
					printf("Enter the value to be swapped: ");
					scanf("%x",&num);
					(b1>b2)?(temp=b1,b1=b2,b2=temp) : 0;
					v=(num & ~((0x1<<b1)|(0x1<<b2)))|((num&(0x1<<b1))<<(b2-b1))|((num&(0x1<<b2))>>(b2-b1));
					printf("%x",v);
					break;

				case 'e':
					printf("enter the value to swap\n");
					scanf("%x",&num);
					for(i=0,j=31;i<j;i++,j--)
					{
						v=(num & ~((0x1<<i)|(0x1<<j)))|((num&(0x1<<i))<<(j-i))|((num&(0x1<<j))>>(j-i));
					}
					printf("%x",v);
					break;

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
					if((up>=65)&&(up<=90))
					{
						up=up+32;
						printf("%c\n",up);
					}
					else if((up>=97)&&(up<=120))
					{
						up=up-32;
						printf("%c\n",up);
					}
					else
						printf("invalid\n");
					break;


				case 'b':
					printf("enter the value:\n");
					scanf("%c",&x1);
					if((x1>=47)&&(x1<=55))
					{
						x1=x1-48;
						printf("%d\n",x1);
					}
					else
						printf("invalid");
				        break;

			}
			break;
		case 5:
			printf("enter the values:\n");
			scanf("%d %d",&a,&b);
			__fpurge(stdin);
			scanf("%d",&n);
			while(n>0)
			{
				c=a+b;
				a=b;
				b=c;
				printf("%d\n",b);
				n--;
			}
			break;






















	}
}
