int main(){
	unsigned int a=0xaabbccdd;
	int *ptr;
	ptr=&a;
	unsigned char c=a;
	printf("%d",c);
	if((*ptr&(0xff))==c)
		printf("Little");
	else
		printf("Big\n");
}
