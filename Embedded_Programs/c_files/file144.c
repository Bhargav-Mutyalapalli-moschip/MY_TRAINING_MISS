#include<stdio.h>
int main()
{
	unsigned int B=1,KB=1024*B,MB=1024*KB,GB=1024*MB;
	unsigned int startadd=0x00000000;
	printf("0x%lx 0x%lx\n",startadd,GB);
	unsigned int part1,part2;
	part1=GB/2;
	printf("0x%lx 0x%lx\n",startadd,part1);
	part2=GB;
	printf("0x%lx 0x%lx\n",part1,part2);
	unsigned int p1blockA,p1blockB;
	p1blockA=part1/2;
	printf("0x%lx 0x%lx\n",startadd,p1blockA-1);
	p1blockB=part1;
	printf("0x%lx 0x%lx\n",p1blockA,part1-1);
	unsigned int p2blockA,p2blockB;
	p2blockA=(3*GB/4);
	printf("0x%lx 0x%lx\n",part1,p2blockA-1);
	p2blockB=GB-1;
	printf("0x%lx 0x%lx\n",p2blockA,p2blockB);
	unsigned int v;
	scanf("%x",&v);
	if((v>=startadd)&&(v<=GB))
	{
		if(v < p1blockA)
		
			printf("part 1 block a");
		else if(v < p1blockB)
			printf("part 1 block b");
		else if(v < p2blockA)
			printf("part 2 block a");
		else
			printf("part 2 block b");
		
	}
	else
		printf("invalid addess");
}
	
		











