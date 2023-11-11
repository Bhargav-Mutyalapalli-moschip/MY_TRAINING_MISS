void upper(char ch)
{
	char count;
	count<<char(ch|' ');
}
int main()
{
	char ch='a';
	int c;
	c>>ch;
	upper(ch);
	printf("The %c\n",ch);
}
