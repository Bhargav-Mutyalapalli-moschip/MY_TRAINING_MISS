int main ()
{
	unsigned int n = 0, num = 0, count = 0, rev_bits = 0;
	printf ("Enter the number: ");
	scanf ("%x", &n);
 
	while (n > 0)
	{
		// keep shifting each bit
		rev_bits = rev_bits << 1;
 
		// if the bit is 1 then we XOR with 1
		if (n & 1 == 1)
		{
			rev_bits = rev_bits ^ 1;
		}
 
		// right shift n
		n = n >> 1;
	}
 
	printf ("\nThe reversed resultant = %x\n", rev_bits);
 
	return 0;
}
