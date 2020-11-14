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
#define ull unsigned long long

using namespace std;

ll exp(ll k, ll l)
{
	ll ans = 1, ki = k;
	while (l > 0)
	{
		if (l & 1 > 0)
			ans *= k;
		l = l >> 1;
		k *= k;
	}
	return ans;
}

ll getNthSubsetSum(ll n, vector<ll> s)
{
	ll ans = 0;

	for (ll i = 0; n > 0; i++)
	{
		if (n % 2 == 1)
		{
			ans += s[s.size() - 1 - i];
		}
		n /= 2;
	}

	return ans;
}

int main()
{
    ll n;
	ll a, b;
	ull ans = 0;

	cin >> n >> a >> b;

	ll nh = n/2;

	

	vector<ll> v1(nh);
	vector<ll> v2(n - nh);
	vector<ll> v1s(exp(2, nh));
	vector<ll> v2s(exp(2, (n - nh)));

	ll i = 0;

	for (; i < nh; i++)
	{
		cin >> v1[i];
	}

	for (; i < n; i++)
	{
		cin >> v2[i - nh];
	}

    ll countSub = 1;
	countSub = exp(2, nh);

	for (ll j = 0; j < countSub; j++)
	{
		ll sum = getNthSubsetSum(j, v1);
        v1s[j] = sum;
	}

    ll countSub2 = 1;
	countSub2 = exp(2, (n - nh));

	for (ll j = 0; j < countSub2; j++)
	{
		ll sum = getNthSubsetSum(j, v2);
        v2s[j] = sum;
	}

	sort(v1s.begin(), v1s.end());
	sort(v2s.begin(), v2s.end());

	for(ll j = 0; j < countSub; j++)
	{
		ll lb = a - v1s[j];
		ll ub = b - v1s[j];

		auto lbi = lower_bound(v2s.begin(), v2s.end(), lb);
		auto ubi = upper_bound(v2s.begin(), v2s.end(), ub);

		if (ubi != v2s.end() && v2s[ubi - v2s.begin()] == ub)
			ubi++;
		ans += ubi - lbi;
	}

	cout << ans;

	return 0;
}
