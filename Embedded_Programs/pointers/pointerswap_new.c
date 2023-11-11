#include<stdio.h>
int main()
{
	unsigned int a=0xaabbccdd,b=0x11223344,z;
	printf("%p ----%p-----%p\n",&a,&b,&z);
	unsigned char *ptr=&a;
	int i,j;
	for(i=0;i<5;i=i+2)
	{
		for(j=i+4;j<10;j=j+6)
		{
			if((*(ptr+i))!=(*(ptr+j)))
			{
				(*(ptr+i))=(*(ptr+i))^(*(ptr+j));
				(*(ptr+j))=(*(ptr+i))^(*(ptr+j));
                                (*(ptr+i))=(*(ptr+i))^(*(ptr+j));
			}
		}
		z=a;
		//printf("%x",*(ptr+i));
	}
	printf("%x ",z);
	printf("\n");

	/*for(i=0;i<8;i++)
	{
		printf("%x ",ptr[i]);
	}*/
}

		        
