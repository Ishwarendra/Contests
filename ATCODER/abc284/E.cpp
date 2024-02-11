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

    std::vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }

    constexpr int stop = 1e6;
    int ans = 0;
    std::vector<int> vis(n);
    std::function<void(int)> dfs = [&](int u)
    {
        if (ans == stop)
            return;

        vis[u] = 1;
        ans++;
        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v);
        }

        vis[u] = 0;
    };
    dfs(0);

    std::cout << ans;

    return 0;
}