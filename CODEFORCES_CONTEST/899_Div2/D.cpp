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

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> siz(n);
    std::vector<i64> cost(n);

    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        siz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            dfs(v, u);
            cost[u] += cost[v];
            siz[u] += siz[v];
        }

        cost[u] += 1LL * siz[u] * (a[u] ^ a[p]);
    }; dfs(0, 0);

    std::vector<i64> ans(n);
    dfs = [&](int u, int p)
    {
        ans[u] = cost[u];
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            auto siz_u = siz[u], siz_v = siz[v];
            auto cost_u = cost[u], cost_v = cost[v];

            cost[u] -= cost[v];
            siz[u] -= siz[v];
            cost[u] += 1LL * siz[u] * (a[u] ^ a[v]);

            cost[v] -= 1LL * siz[v] * (a[v] ^ a[u]);
            siz[v] += siz[u];
            cost[v] += cost[u];

            // print(cost)

            dfs(v, u);

            siz[u] = siz_u, siz[v] = siz_v;
            cost[u] = cost_u, cost[v] = cost_v;
        }
    }; dfs(0, 0);

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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