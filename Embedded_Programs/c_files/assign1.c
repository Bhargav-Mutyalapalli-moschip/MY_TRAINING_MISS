#include<stdio.h>
int main()
{
	printf("The Bitwise Operations: ");
	printf("THE OPTIONS ARE:\n 1-Count no of zeros\n ");
	int val,h,prog,count=0,i,x,temp;
	unsigned int num,v,b1,b2,j;
	printf("Enter the program number: ");
	scanf("%d",&prog);
	switch(prog)
	{
		case 1:
			printf("Enter the value to count the number of zeros:\n ");
			scanf("%x",&num);
			for(i=0;i<(32-0);i++)
			{
				if((num&(0x1))==0)
				count++;

			num=num>>1;
			}
			printf("The count is:%d\n",count);

			break;
		case 2:
			 printf("Enter the value to count the number of combinational bits:\n ");
                        scanf("%x",&num);
                        for(i=0;i<(32-3);i++)
                        {
                                if((num&(0x7))==(0x5))
                                count++;

                        num=num>>1;
                        }
                        printf("The cobination count is :%d\n",count);

                        break;
		case 3:
			printf("enter the value to convert int binary: ");
			scanf("%x",&num);
			for(i=0;i<32;i++)
			{
				if(((num&(0x1<<i))>>i)==0)
				printf("0");
				else
					printf("1");

			        
			}
		case 4:
			printf("enter the byte or bits to be swapped: ");
			scanf("%d %d",&b1,&b2);
			__fpurge(stdin);
			printf("Enter the value to be swapped: ");
			scanf("%x",&num);
			(b1>b2)?(temp=b1,b1=b2,b2=temp) : 0;
			v=(num & ~((0x1<<b1)|(0x1<<b2)))|((num&(0x1<<b1))<<(b2-b1))|((num&(0x1<<b2))>>(b2-b1));
			printf("%x",v);
		case 5:
			printf("Enter a value: ");
			scanf("%x",&num);
			for(i=0;i<(8-3);i++)
			{
				
				if(((num&(0x7)<<i)>>i)==(0x5))
				{
					num=num|((0x7)<<i);
				}



				
			//num=num>>1;
			}
			printf("%x",num);
			break;


			



	}


}
