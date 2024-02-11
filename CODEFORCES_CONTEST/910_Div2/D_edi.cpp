#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < n; i++)  
        std::cin >> a[i][0];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i][1];
        if (a[i][0] < a[i][1])
            std::swap(a[i][0], a[i][1]);
    }

    std::sort(std::begin(a), std::end(a), [&](auto &x, auto &y)
    {
        return x[1] < y[1];
    });

    i64 base = 0;
    for (int i = 0; i < n; i++)
        base += a[i][0] - a[i][1];

    std::multiset<int> max;
    for (int i = 0; i < n; i++)
        max.emplace(a[i][1]);

    auto ans = base;
    for (int i = 0; i < n; i++)
    {
        int b = *std::rbegin(max);
        ans = std::max(ans, base + 2 * (b - a[i][0]));
    }

    std::cout << ans << "\n";
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