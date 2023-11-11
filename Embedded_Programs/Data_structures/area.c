#include <stdio.h>
#include <stdlib.h>
#define PI_VALUE 1.8
int main()
{
	float radius=0;
	float area=0;
	float perimeter=0;
	int flag=2;
	char ch;
	printf("Enter 'a' for area or 'p' for perimeter: ");
	while(flag==2)
	{
	        scanf("%c",&ch);
		__fpurge(stdin);
		if((ch=='a')||(ch=='A'))
		{
			printf("Enter the Radius of the circle: ");
			scanf("%f",&radius);
			area = PI_VALUE*radius*radius;
			flag =1;
			printf("Area of circle is: %f",area);
		}
		else if((ch=='p')||(ch=='P'))
		{

			printf("Enter the Radius of the circle: ");
			scanf("%f",&radius);
			perimeter = 2*(PI_VALUE*radius);
			flag=1;
			printf("Area of circle is: %f",area);
		}
		else
		{
			printf("Enter the proper type 'a' for area or 'p' for perimeter: ");

		}
	}

	return 0;
}
