#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> p;

void solve()
{
    int n;
    std::cin >> n;

    int can = 1;
    while (can)
    {   
        can = 0;
        for (int i = 0; i < std::size(p); i++)
        {
            if (n % p[i] == 0)
                n /= p[i], can = 1;
        }
    }

    if (n == 1)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int mask = 2; mask < 32; mask++)
    {
        int num = 0, mul = 1;
        for (int i = 0; i < 5; i++, mul *= 10)
            num += (mask >> i & 1) * mul;

        if (num <= 2e5)
            p.emplace_back(num);
    }

    std::reverse(std::begin(p), std::end(p));

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}