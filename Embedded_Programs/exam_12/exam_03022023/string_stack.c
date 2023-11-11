#include<stdio.h> 
char *getstring()
{
       	char str[] = "HELLO MISS"; 
	char *ptr = str; 
	return ptr;
} 
char* putstring ()      
{	
	char put[] = "BABY"; 
}
int main() 
{ 
	char *str = getstring(); 
	char *ptrl = putstring();
	printf("%s", str); 
	return 0;
}
