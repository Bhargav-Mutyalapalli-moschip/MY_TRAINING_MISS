int ascii_conver(char x1)
{
	if((x1>=47)&&(x1<=55))
	{
		x1=x1-48;
		return x1;
	}
	else
		return -1;
}
