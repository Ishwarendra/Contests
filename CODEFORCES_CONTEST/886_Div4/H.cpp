#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)  
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, -w);
    }

    std::vector<i64> pos(n, -inf);
    bool ok = true;

    std::function<void(int, i64)> dfs = [&](int u, i64 x)
    {
        pos[u] = x;
        for (auto [v, w] : adj[u])
        {
            if (pos[v] == -inf)
                dfs(v, x + w);
            else if (pos[v] != x + w)
                ok = false;
        }
    };

    for (int i = 0; i < n; i++)
    {
        if (pos[i] == -inf)
            dfs(i, 0);
    }

    std::cout << (ok ? "YES\n" : "NO\n");
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