#include<stdio.h>
int main()
{
	int a,b,count=0,temp;
	scanf("%d",&a);
	if(a!=0)
	{

        	while(a!=0)
	        {

		        a=a/10;
		        count++;
	        }    
	        printf("%d",count);
	}
	else
        {
		count++;
		printf("%d",count);

}
}
