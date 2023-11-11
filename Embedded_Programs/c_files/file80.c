 #include <stdio.h>
int main() 
{
    int a[10], number, i, count=0,bulbs;
    printf("\n Please Enter the Number You want to Convert  :  ");
    scanf("%d", &number);
    
    for(i = 0; number > 0; i++)
    {
        a[i] = number % 2;
        number = number / 2;
    }
    
    printf("\n Binary Number of a Given Number =  ");
    for(i = i - 1; i >= 0; i--)  {

        printf("%d", a[i]);
	if(a[i]==1)
        {
		count++;
	}



    }
    printf("\nBulbs is %d",count);


    
    
    
    printf("\n");
    return 0;
}


