int set_operation(unsigned int num,int bit)
{
	//int bit;
	unsigned int out,mask=0x1;
        out=num|(mask<<bit);
	return out;
	
	
}
