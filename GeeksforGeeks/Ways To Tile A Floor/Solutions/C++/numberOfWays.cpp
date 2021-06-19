long long numberOfWays(long long N)
{
	long long modulo = 1000000007;

	// This is nothing but fibonacci series in modulo 10^9 + 7.
	// For N = 1 or 2, we return N itself.

	if (N == 1 || N == 2)
		return N;

	// In other cases, we calculate the Nth fibonacci number using Dynamic Programming.

	long long fb_minus_1 = 2;	// This variable holds the (i - 1)th fibonacci number.
	long long fb_minus_2 = 1;	// This variable holds the (i - 2)th fibonacci number.
	long long fb;				// This variable holds the (i)th fibonacci number.

	for (long long i = 3; i <= N; i++)
	{
		fb = fb_minus_1 + fb_minus_2;
		fb_minus_2 = fb_minus_1;
		fb_minus_1 = fb;

		fb %= modulo;
		fb_minus_1 %= modulo;
		fb_minus_2 %= modulo;
	}

	return fb;
}