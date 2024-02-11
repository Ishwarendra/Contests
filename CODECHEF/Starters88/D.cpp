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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::map<int, std::vector<std::pair<int, int>>> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            m[a[i] + a[j]].emplace_back(i, j);
    }

    if (n == 1)
    {
        std::cout << "1\n";
        return;
    }

    int ans = n - 2;
    for (auto &[sum, p] : m)
    {
        std::sort(std::begin(p), std::end(p), [&](auto &x, auto &y)
        {
            return x.second < y.second;
        });

        int r = -1;
        int cur = 0;

        for (int i = 0; i < std::size(p); i++)
        {
            if (p[i].first > r)
                cur++, r = p[i].second;
        }

        ans = std::min(ans, n - 2 * cur);
    }

    std::cout << ans << "\n";
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