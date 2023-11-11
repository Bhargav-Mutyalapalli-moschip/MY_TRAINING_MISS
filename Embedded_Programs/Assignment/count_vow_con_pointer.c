#include<stdio.h>
#include<string.h>
void count_vowels(char *str);
int main()
{
	char str[100];
	printf("enter the string:");
	scanf("%[^\n]",str);
	count_vowels(str);
}
void count_vowels(char *str)
{
	int vowcount=0,concount=0;
	while(str[0] != '\0')
	{
		if(str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u')
		vowcount++;
		else if(str[0] == 'A' || str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U')
		vowcount++;
		else if(str[0] >= 'a' && str[0] <= 'z')
		concount++;
		else if(str[0] >= 'A' && str[0] <= 'Z')
		concount++;
		str++;
	}
	printf("Vowel count:%d------Consonant count:%d\n",vowcount,concount);
}

