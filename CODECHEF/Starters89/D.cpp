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
        std::cin >> a[i][1];

    std::sort(std::begin(a), std::end(a), [&](auto &x, auto &y) 
    {
        return x[1] < y[1];
    });

    std::multiset<std::pair<int, int>> m;
    std::vector<int> steal(n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        if (!m.empty())
        {
            auto [min, min_id] = *std::begin(m);
            if (min < a[i][1])
                steal[i] = min_id;
        }
        m.emplace(a[i][0], i);
    }

    std::vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (steal[i] != -1)
            dp[i] = dp[steal[i]] + 1;
    }

    print(steal)

    std::cout << *std::max_element(std::begin(dp), std::end(dp)) << "\n";
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