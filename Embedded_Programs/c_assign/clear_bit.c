int clear_bit(unsigned int num,int bit)
{
	unsigned int out,mask=0x1;
	out=num&(~(mask<<bit));
	return out;
}
