#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;
    a--, b--;

    std::vector<std::pair<int, int>> c(n);
    for (auto &[x, y] : c)
        std::cin >> x >> y;

    auto getDist = [&](int i, int j) -> i64
    {
        if (i < k and j < k)
            return 0;

        return 1LL * std::abs(c[i].first - c[j].first) + std::abs(c[i].second - c[j].second);
    };

    i64 min = 1e18;
    for (int i = 0; i < k; i++)
        min = std::min(min, getDist(i, b));

    i64 ans = 1e18;

    for (int i = 0; i < n; i++)
    {
        if (i >= k)
            ans = std::min(ans, getDist(a, i) + getDist(i, b));
        else
            ans = std::min(ans, getDist(a, i) + min);
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