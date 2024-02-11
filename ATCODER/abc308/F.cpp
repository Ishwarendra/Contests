#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::multiset<int> p;
    std::vector a(m, std::array<int, 2>());

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        p.emplace(x);
    }

    for (int i = 0; i < m; i++)
        std::cin >> a[i][0];
    for (int i = 0; i < m; i++)
        std::cin >> a[i][1];

    std::sort(std::begin(a), std::end(a), [&](auto x, auto y)
    {
        return x[1] > y[1];
    });

    i64 ans = 0;
    for (auto [L, D] : a)
    {
        auto it = p.lower_bound(L);
        if (it == std::end(p))
            continue;

        ans += *it - D;
        p.erase(it);
    }

    for (auto x : p)
        ans += x;

    std::cout << ans;
    
    return 0;
}