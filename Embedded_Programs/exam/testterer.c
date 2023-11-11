#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void replaceWordInText(const char *text, const char *oldWord, const char *newWord) {
	int i = 0, cnt = 0;
	int len1 = strlen(newWord);
	int len2 = strlen(oldWord);
	for (i = 0; text[i] != '\0'; i++) {
		if (strstr(&text[i], oldWord) == &text[i]) {
			cnt++;
			i += len2 - 1;
		}
	}
	char *newString = (char *)malloc(i + cnt * (len1 - len2) + 1);
	i = 0;
	while (*text) {
		if (strstr(text, oldWord) == text) {
			strcpy(&newString[i], newWord);
			i += len1;
			text += len2;
		}
		else
			newString[i++] = *text++;
	}
	printf("New String: %s\n", newString);
}
int main() {
	char str[200];
	printf("enter main string:");
	scanf("%[^\n]",str);
	char c[50] ;
	printf("enter serach string:");
	scanf("%s",c);
	char d[50];
	printf("enter replace string:");
	scanf("%s",d);
	char *result = NULL;
	printf("Original string: %s\n", str);
	replaceWordInText(str, c, d);
	return 0;
}
