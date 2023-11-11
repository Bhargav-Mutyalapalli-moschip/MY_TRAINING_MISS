#include <stdio.h>
#include <string.h>
int main ()
{
  char str[100];
  char temp;
	int i, j,len;
  printf("C Program to sort character in descending order\n");
  printf("Please enter the string : ");
  scanf("%[^\n]",str);
 //len = strlen(str);
	for (i = 0; str[i]!='\0'; i++) {
		for (j = i+1;str[j]!='\0'; j++) {
			if (str[i]> str[j]) {
					temp = str[j];
					str[j] = str[i];
					str[i] = temp;
			}
		}
	}
	printf("After sorting character in descending order : %s", str);
	return 0;
}
