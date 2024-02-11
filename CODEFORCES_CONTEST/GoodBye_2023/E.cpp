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

    std::vector<int> p(n);
    std::vector<std::vector<int>> adj(n);
    const int m = std::__lg(n) + 2;
    std::vector dp(n, std::vector(m, 0));
    std::vector num(n, std::vector(m, std::set<int>()));

    for (int i = 0; i < n - 1; i++)  
    {
        std::cin >> p[i];
        p[i]--;
        adj[p[i]].emplace_back(i);
        adj[i].emplace_back(p[i]);
        dp[i][0] = p[i];
    }

    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        num[i][0].emplace(a);
    }

    auto add = [&](auto &s, auto &t)
    {
        for (auto x : t)
            s.emplace(x);
    };

    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
            add(num[i][j], num[dp[i][j - 1]]);
            add(num[i][j], num[dp[dp[i][j - 1]][j - 1]]);
        }
    }
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