#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, c;
    std::cin >> n >> k >> c;  

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<i64> d(n, -1), dp(n);
    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        d[u] = d[p] + 1;
        for (int v : adj[u])
        {
            if (v != p)
            {
                dfs(v, u);  
                dp[u] = std::max(dp[u], dp[v] + 1);
            }
        }
    }; dfs(0, 0);

    i64 ans = 0;
    dfs = [&](int u, int p)
    {
        // print(dp[u], d[u], u)
        ans = std::max(ans, dp[u] * k - c * d[u]);
        std::multiset<std::pair<i64, int>, std::greater<>> m; 
        for (int v : adj[u])
            m.emplace(dp[v], v);

        for (int v : adj[u])
        {
            if (v == p)
                continue;

            auto old_u = dp[u], old_v = dp[v];
            
            auto [max1, v1] = *std::begin(m);
            if (v1 == v)
            {
                if (std::size(m) == 1)
                    max1 = -1;
                else
                    max1 = (++std::begin(m))->first;
            }

            dp[u] = max1 + 1;
            dp[v] = std::max(dp[v], dp[u] + 1);
            dfs(v, u);
            dp[u] = old_u, dp[v] = old_v;
        }
    }; dfs(0, 0);

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