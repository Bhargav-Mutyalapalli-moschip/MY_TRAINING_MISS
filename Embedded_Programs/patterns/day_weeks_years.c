#include<stdio.h>
int main()
{
	int days=1329,res,var;
	var=days/365;
	printf("The years are:%d\n",var);
	var=(days-(var*365))/30;
	printf("The weeks are  are:%d\n",var);
	var=(days-(var*365))/12;
	printf("The moths are are:%d\n",var);
	var=(days % 365)/7;
	printf("The weeks are:%d\n",var);


	
}
