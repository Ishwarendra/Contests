#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
using i128 = __int128;
using u128 = __uint128_t;

std::ostream &operator<<(std::ostream &os, i128 x) 
{
    std::string s;
    bool neg = false;
    if (x < 0)
        neg = true, x = -x;
    if (x == 0)
        s = "0";
    
    while (x)
    {
        s += '0' + x % 10;
        x /= 10;
    }

    if (neg)
        s += '-';
    s = std::string(std::rbegin(s), std::rend(s));
    return os << s;
}

void solve()
{
    int n, p;
    i64 m;
    std::cin >> n >> m >> p;

    int den = n * (n + 1);
    if ((2 * m) % den)
        std::cout << "-1\n";
    else
        std::cout << i128(2) * m / den * p << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}