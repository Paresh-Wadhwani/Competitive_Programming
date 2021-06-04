void sort012(int a[], int n)
{
	long long zeroes = 0, ones = 0, twos = 0;
	
	for (long long i = 0; i < n; i++)
	{
		if (a[i] == 0)
			zeroes++;

		if (a[i] == 1)
			ones++;

		if (a[i] == 2)
			twos++;
	}
	
	for (long long i = 0; i < n; i++)
	{
		if (zeroes > 0)
		{
			a[i] = 0;
			zeroes--;
		}
		else if (ones > 0)
		{
			a[i] = 1;
			ones--;
		}
		else if (twos > 0)
		{
			a[i] = 2;
			twos--;
		}
	}
}