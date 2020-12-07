#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000000

using namespace std;

vector< vector<ll> > matrixMultiply(vector< vector<ll> > a, vector< vector<ll> > b)
{
	ll r1 = a.size(), c1 = b.size(), c2 = b[0].size();

	vector< vector<ll> > ans(r1, vector<ll>(c2));

	for(ll i = 0; i < r1; i++)
	{
		for(ll j = 0; j < c2; j++)
		{
			ll element = 0;
			for(ll k = 0; k < c1; k++)
			{
				element += (a[i][k] * b[k][j]) % mod;
			}

			ans[i][j] = element % mod;
		}
	}

	return ans;
}

vector< vector<ll> > matrixExp(vector< vector<ll> > a, ll p)
{
	if (p == 1)
	{
		return a;
	}

	vector< vector<ll> > ans(a.size(), vector<ll>(a[0].size(), 0));

	for(ll i = 0; i < a.size(); i++)
	{
		for(ll j = 0; j < a.size(); j++)
		{
			if (i == j)
			{
				ans[i][j] = 1;
			}
		}
	}

	while (p > 0)
	{
		if (p & 1 > 0)
		{
			ans = matrixMultiply(ans, a);
		}

		p = p >> 1;
		a = matrixMultiply(a, a);
	}

	return ans;
}

ll seq(vector<ll> a, vector<ll> c, ll n, ll k)
{
	if (a.size() >= n)
	{
		return a[n - 1];
	}

	vector< vector<ll> > tr(k, vector<ll>(k));

	for (ll i = 0; i < k; i++)
	{
		for (ll j = 0; j < k; j++)
		{
			if (i + 1 == j)
			{
				tr[i][j] = 1;
			}
			else if (i == k - 1)
			{
				tr[i][j] = c[k - j - 1];
			}
		}
	}

	vector< vector<ll> > co(k, vector<ll>(1));

	for (ll i = 0; i < k; i++)
	{
		co[i][0] = a[i];
	}

	vector< vector<ll> > ans = matrixMultiply(matrixExp(tr, n - k), co);

	return ans[k - 1][0];
}

int main()
{
	ll t;

	cin >> t;

	while (t--)
	{
		ll k;

		cin >> k;

		vector<ll> a(k);

		for (ll i = 0; i < k; i++)
		{
			cin >> a[i];
		}

		vector<ll> c(k);

		for (ll i = 0; i < k; i++)
		{
			cin >> c[i];
		}

		ll n;

		cin >> n;

		cout << seq(a, c, n, k) << '\n';
	}

	return 0;
}