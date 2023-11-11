void gotostat_prog(int a,int b)
{
	int sum=0,temp=0,rem,i=1,temp1=0;
        if(a>b)
        temp=a,a=b,b=temp;
        

binary:
       temp=a;


       if(b>=a)
       {


               sum=0;
               i=1;


binary1:

	       rem=temp%10;
	       if(rem>1)
	       {
		       a++;
		       goto binary;
	       }
	       sum=sum+(rem*i);
	       temp=temp/10;
	       i=i*2;
	       if(temp!=0)
		       goto binary1;
	       printf("%d %d\n",a,sum);
	       a++;
	       if(rem<=1)
		       goto binary;

       }
}

