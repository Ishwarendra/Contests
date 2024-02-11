#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::array<std::queue<int>, 3> a{};
    for (int i = 0; i < 3; i++)  
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            std::cin >> x;
            a[i].emplace(x);
        }
    }

    int cur = 0;
    auto getBit = [&](int num, int pos) { return num >> pos & 1; };

    auto valid = [&](int num)
    {
        for (int i = 0; i < 30; i++)
        {
            if (!getBit(x, i) and getBit(num, i))
                return false;
        }

        return true;
    };

    int can = 1;
    while (can)
    {
        can = 0;
        for (int i = 0; i < 3; i++)
        {
            if (!a[i].empty() and valid(a[i].front()))
            {
                cur |= a[i].front(), a[i].pop();
                can = 1;
            }
        }
    }

    std::cout << (cur == x ? "Yes\n" : "No\n");
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