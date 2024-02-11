#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> c(n);
    for (int i = 0; i < n; i++)  
        std::cin >> c[i];
    for (int i = 0; i < k; i++)
    {
        int p;
        std::cin >> p;
        c[p - 1] = 0;
    }

    constexpr i64 inf = 1e18;
    std::vector<i64> dp(n, inf);

    std::vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;

        for (int j = 0; j < m; j++)
        {
            int x;
            std::cin >> x;
            x--;

            adj[i].emplace_back(x);
        }
    }

    std::function<void(int)> dfs = [&](int u)
    {
        dp[u] = c[u];
        i64 sum = inf;
        for (int v : adj[u])
        {
            if (dp[v] == inf)
                dfs(v);

            if (sum == inf)
                sum = 0;

            sum += dp[v];
        }

        dp[u] = std::min(dp[u], sum);
    }; 

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == inf)
            dfs(i);
    }

    for (int i = 0; i < n; i++)
        std::cout << dp[i] << " \n"[i == n - 1];
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