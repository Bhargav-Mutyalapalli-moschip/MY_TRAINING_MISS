#include<stdio.h>
void int_ascii(int temp);
int main()
{
	int h,sum=0,rem,temp,count=0,i,j=0,k=0;
	int a;
	scanf("%d",&a);
	temp=a;
	void (*asciiptr)(int);
	asciiptr=int_ascii;
	asciiptr(temp);



}
void int_ascii(int temp)
{

        int count=0,rem,i,a=temp;;
        while(temp!=0)
	{
		rem=temp%10;
		count++;
		temp=temp/10;
	}
	printf("%d\n",count);
	temp=a;	
	char arr[count];
	printf("%s\n",arr);
	i = count  - 1;
	while(temp > 0)
	{
		printf("Enter converted loop\n");
		rem=temp%10;
		arr[i]=rem+48;
		temp=temp/10;
		printf("the temp is:==%d-------------%d\n",temp,rem);
		i--;

	}
	arr[count]='\0';


	printf("%s\n",arr);

}

