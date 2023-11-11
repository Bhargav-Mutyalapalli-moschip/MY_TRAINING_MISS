#include<stdio.h>  
int main() 
{ 
int a=10,b=20,c; 
asm❴ 
// ax and bx are general purpose register in x86 architecture   
MOV ax, a 
MOV bx,b 
add  ax,bx 
MOV c,ax 
❵  
printf(“the sum of two number is => %d”, c); 
} 

