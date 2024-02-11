#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18 + 1;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector a(n, std::array {-inf, inf});
    bool possible = true;
    for (int i = 0; i < m; i++)
    {
        int id, x;
        std::cin >> id >> x;
        id--;

        if (a[id] != std::array {-inf, inf})
            possible = false;

        a[id] = {x, x};
    }

    std::vector d(n, std::vector(n, inf));
    std::vector<std::set<int>> adj(n);
    std::vector<int> vis(n);
    std::function<void(int)> dfs = [&](int u)
    {
        vis[u] = 1;

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                a[v][0] = std::max(a[v][0], a[u][0] - d[u][v]);
                a[v][1] = std::min(a[v][1], a[u][1] + d[u][v]);

                dfs(v);
            }
        }
    };

    for (int i = 0; i < k; i++)
    {
        int u, v, d_;
        std::cin >> u >> v >> d_;
        u--, v--;

        d[u][v] = std::min<i64>(d_, d[u][v]);
        d[v][u] = std::min<i64>(d_, d[v][u]);
        adj[u].emplace(v);
        adj[v].emplace(u);

        if (a[u][0] != -inf)
        {
            std::fill(std::begin(vis), std::end(vis), 0);
            dfs(u);
        }

        if (a[v][0] != -inf)
        {
            std::fill(std::begin(vis), std::end(vis), 0);
            dfs(v);
        }
    }

    for (int i = 0; i < n; i++)
        dfs(i);

    for (auto &[min, max] : a)
        possible &= min <= max;

    std::cout << (possible ? "YES\n" : "NO\n");
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