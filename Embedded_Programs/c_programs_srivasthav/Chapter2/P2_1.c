/*P2.1 Program to find out the size and limits of data types*/
#include<stdio.h>
#include<limits.h>
#include<float.h>
int main(void)
{
	printf("sizeof(char) = %ld\n",sizeof(char));
	printf("sizeof(short) = %ld\n",sizeof(short));
	printf("sizeof(int) = %ld\n",sizeof(int));
	printf("sizeof(long) = %ld\n",sizeof(long));
	printf("sizeof(float) = %ld\n",sizeof(float));
	printf("sizeof(double) = %ld\n",sizeof(double));
	printf("sizeof(long double) = %ld\n",sizeof(long double));

	printf("SCHAR_MIN = %d\n",SCHAR_MIN);
	printf("SCHAR_MAX = %d\n",SCHAR_MAX);
	printf("UCHAR_MAX = %d\n",UCHAR_MAX);

	printf("SHRT_MIN = %d\n",SHRT_MIN);
	printf("SHRT_MAX = %d\n",SHRT_MAX);
	printf("USHRT_MAX = %d\n",USHRT_MAX);

	printf("INT_MIN = %d\n",INT_MIN);
	printf("INT_MAX = %d\n",INT_MAX);
	printf("UINT_MAX = %d\n",UINT_MAX);

	printf("LONG_MIN = %ld\n",LONG_MIN);
	printf("LONG_MAX = %ld\n",LONG_MAX);
	printf("ULONG_MAX = %lu\n",ULONG_MAX);

	printf("FLT_MIN = %e\n",FLT_MIN);
	printf("FLT_MAX = %e\n",FLT_MAX);

	printf("DBL_MIN = %e\n",DBL_MIN);
	printf("DBL_MAX = %e\n",DBL_MAX);

	printf("LDBL_MIN = %le\n",LDBL_MIN);
	printf("LDBL_MAX = %le\n",LDBL_MAX);

	/*Number of digits of precision*/
	printf("FLT_DIG = %d\n",FLT_DIG);
	printf("DBL_DIG = %d\n",DBL_DIG);
	printf("LDBL_DIG = %d\n",LDBL_DIG);
	return 0;
}

/*
   sizeof(char) = 1
   sizeof(short) = 2
   sizeof(int) = 4
   sizeof(long) = 8
   sizeof(float) = 4
   sizeof(double) = 8
   sizeof(long double) = 16
   SCHAR_MIN = -128
   SCHAR_MAX = 127
   UCHAR_MAX = 255
   SHRT_MIN = -32768
   SHRT_MAX = 32767
   USHRT_MAX = 65535
   INT_MIN = -2147483648
   INT_MAX = 2147483647
   UINT_MAX = -1
   LONG_MIN = -9223372036854775808
   LONG_MAX = 9223372036854775807
   ULONG_MAX = 18446744073709551615
   FLT_MIN = 1.175494e-38
   FLT_MAX = 3.402823e+38
   DBL_MIN = 2.225074e-308
   DBL_MAX = 1.797693e+308
   LDBL_MIN = 0.000000e+00
   LDBL_MAX = 0.000000e+00
   FLT_DIG = 6
   DBL_DIG = 15
   LDBL_DIG = 18
   */
