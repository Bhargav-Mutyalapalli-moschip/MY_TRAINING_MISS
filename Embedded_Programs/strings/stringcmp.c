int main()
{
	char str1[]="deep";
	int x=0x12;
	char str2={'d','e','e','p'};
	printf("%p-%p",x,&x);
	if(strcmp(str1,str2)==0)
		printf("same\n");
	else
		printf("Different\n");
	return 0;
}
