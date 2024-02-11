#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 x;
    std::cin >> x;

    auto getBit = [&](auto num, auto pos) { return (num >> pos) & 1; };

    i64 a = 0, b = 0;
    std::set<int> free;
    for (int i = 0; i <= 32; i++)  
    {
        if (getBit(x, i))
        {
            if (b == 0)
                b |= (1LL << i);
            else
                a |= (1LL << i);
        }
        else
            free.emplace(i);
    }

    if (x % 2)
    {
        std::cout << "-1\n";
        return;
    }

    x /= 2;
    for (int i = 0; i <= 32; i++)
    {
        if (getBit(x, i))
        {
            if (!free.count(i))
            {
                std::cout << "-1\n";
                return;
            }
            else
            {
                a |= (1LL << i);
                b |= (1LL << i);
            }
        }
    }

    std::cout << a << " " << b << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}