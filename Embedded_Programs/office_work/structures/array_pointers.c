#include<stdio.h>
#define NUM 4
int ind=0;
struct fruits
{
	char name[32];
	int quantity;
	float price;
};
struct pointers
{
	struct fruits*(*f_memory_alloc)();
	void(*f_read)(struct fruits **);
	void(*f_display)(struct fruits *);
};
struct fruits *memory_alloc();
void read(struct book **ptr);
int main()
{
	struct fruits *main[NUM];
	struct pointers fun;
	fun.f_memeory_alloc=memory_alloc;
	fun.f_read=read;
	fun.f_display=display;
	int prog,i;
	while(1)
	{
		printf("0.exit\n1.memory_alloc\n2.read\n3.display\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				exit(0);

			case 1://ind++;
				for(i=0;i<NUM;i++)
				{
					main[i]=fun.f_memory_alloc;
				}
			       //ind=0;
			       break;
			case 2:
			       //ind++;
			       fun.f_read(main);
			       break;

			 
	        }
	}
}
struct fruits *memory_alloc()
{
	struct fruits *ptr;
	int i;
	ptr=(struct fruits*)malloc(1*sizeof(struct fruits));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
}
void read(struct book **ptr)
{
	int i,j=-1;
	for(i=0;i<NUM;i++)
	{
		for(j=0;j<1;j++)
		{
			scanf("%s",ptr[i]);
		}
	}
}






