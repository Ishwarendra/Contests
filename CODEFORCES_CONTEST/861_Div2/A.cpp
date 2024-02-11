#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> dp[10];

void solve()
{
    int l, r;
    std::cin >> l >> r;

    for (int d = 9; d >= 0; d--)
    {
        auto it = std::lower_bound(std::begin(dp[d]), std::end(dp[d]), l);
        if (it == std::end(dp[d]) or *it > r)
            continue;

        std::cout << *it << "\n";
        return;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto diff = [&](int x)
    {
        std::string s = std::to_string(x);
        std::sort(std::begin(s), std::end(s));

        return s.back() - s.front();
    };

    for (int i = 1; i <= 1e6; i++)
        dp[diff(i)].emplace_back(i);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}