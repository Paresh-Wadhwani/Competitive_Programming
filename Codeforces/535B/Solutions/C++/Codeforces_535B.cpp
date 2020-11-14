#include <iostream>
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
 
int main()
{
	ull n, ans = 0;
	cin >> n;
 
	stringstream ss;
 
	string str;
 
	ss << n;
	ss >> str;
 
 
	ans += exp(2, str.size()) - 2;
 
	size_t i7 = str.find('7');
 
	while (i7 != string::npos)
	{
		i7++;
		ans += exp(2, str.size() - i7);
		i7 = str.find('7', i7);
	}

	ans++;      // 1 based index
 
	cout << ans;
 
	return 0;
}
