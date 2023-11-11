
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
