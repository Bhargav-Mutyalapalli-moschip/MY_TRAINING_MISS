char ascii_char(char up)
{
	if((up>=65)&&(up<=90))
	{
		up=up+32;
		return up;
	}
	else if((up>=97)&&(up<=120))
	{
		up=up-32;
		return up;
	}
	else
		return -1;
}
