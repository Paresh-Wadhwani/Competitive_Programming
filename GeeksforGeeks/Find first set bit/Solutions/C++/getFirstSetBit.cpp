unsigned int getFirstSetBit(int n)
{
	int i = 0;

	while(n!=0)
	{
		if(n%2 == 0)
		{
			n = n/2;
			i = i + 1;
		}
		else
		{
			i++;
			break;
		}
	}
	
	return i;
}