#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    auto query = [&](int i, int j)
    {
        std::cout << "? " << i + 1 << ' ' << j + 1 << std::endl;
        int g;
        std::cin >> g;

        return g;
    };

    int n;
    std::cin >> n;

    int last = query(0, 1);
    int l1 = 0, l2 = 1;
    for (int i = 2; i < n; i++)
    {
        auto g1 = query(l1, i);
        auto g2 = query(l2, i);

        if (last > std::max(g1, g2))
            continue;

        if (g1 > g2)
        {
            l2 = i;
            last = g1;
        }
        else
        {
            l1 = i;
            last = g2;
        }
    }

    std::cout << "! " << l1 + 1 << ' ' << l2 + 1 << std::endl;
    int g;
    std::cin >> g;

    if (g == -1)
        std::exit(0);
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