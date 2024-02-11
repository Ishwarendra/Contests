#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        std::cin >> u >> v >> c;
        adj[--u].emplace_back(--v, c);
        adj[v].emplace_back(u, c);
    }

    int ans = 0, sum = 0;

    std::vector<int> vis(n);
    std::function<void(int, int)> dfs = [&](int u, int add)
    {
        sum += add;
        ans = std::max(ans, sum);
        vis[u] = 1;

        for (auto [v, w] : adj[u])
        {
            if (!vis[v])
                dfs(v, w);
        }

        vis[u] = 0;
        sum -= add;
    }; 

    for (int i = 0; i < n; i++)
        dfs(i, 0);

    std::cout << ans;

    return 0;
}