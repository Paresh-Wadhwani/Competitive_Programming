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

ull sumDigit(ull n)
{
    ull ans = 0;

    while (n)
    {
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

int main()
{
    ull n, sumf = 0;
    cin >> n;

    ull sumd = sumDigit(n);

    for(ull j = 2; j <= n; j++)
    {
        if(n % j == 0)
        {
            sumf += sumDigit(j);
            n /= j;

            if (n % j == 0)
            {
                j--;
            }
        }
    }

    cout << (sumd == sumf);
    
    return 0;
}
