#include<stdio.h>
int main()
{
        int x=20;
        int z=64;
        int y=40;
        int **ptr;
        ptr=(int*)malloc(3*sizeof(int));
        ptr[0]=&x;
        ptr[1]=&y;
        printf("%d\n",ptr[0][1]);
}
~                                                                                                                                                                                                         
~        
